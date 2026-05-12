/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:48:28 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/12 04:06:03 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

static void	_handle_abs_path(t_cmd *m_cmd, char **m_path)
{
	struct stat	path_stat;

	if (access(m_cmd->m_args[0], F_OK) == -1)
	{
		perror(m_cmd->m_args[0]);
		minishell_exit(127);
	}
	stat(m_cmd->m_args[0], &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_puterr2(PRE_OUT, m_cmd->m_args[0], ": Is a directory\n");
		minishell_exit(126);
	}
	*m_path = m_cmd->m_args[0];
}

static void	_handle_path(t_cmd *m_cmd, t_env *m_env, char **m_path)
{
	if (ft_strchr(m_cmd->m_args[0], '/'))
		_handle_abs_path(m_cmd, m_path);
	else
	{
		*m_path = get_m_path(m_cmd->m_args[0], m_env);
		if (!*m_path)
		{
			ft_puterr2(PRE_OUT, m_cmd->m_args[0], ": command not found\n");
			minishell_exit(127);
		}
	}
	if (access(*m_path, F_OK) == -1)
	{
		perror(m_cmd->m_args[0]);
		minishell_exit(127);
	}
	if (access(*m_path, X_OK) == -1)
	{
		perror(m_cmd->m_args[0]);
		minishell_exit(126);
	}
}

void	exec_child_process(t_cmd *m_cmd_list, t_env *m_env_list)
{
	char		*m_path;
	char		**m_envp;

	if (apply_redirections(m_cmd_list->m_redirect_list) == -1)
		minishell_exit(1);
	if (!m_cmd_list->m_args || !m_cmd_list->m_args[0])
		minishell_exit(0);
	if (is_builtin(m_cmd_list->m_args[0]))
	{
		exec_builtin(m_cmd_list, &m_env_list);
		minishell_exit(0);
	}
	_handle_path(m_cmd_list, m_env_list, &m_path);
	m_envp = t_env__to_m_array(m_env_list);
	execve(m_path, m_cmd_list->m_args, m_envp);
	perror(m_cmd_list->m_args[0]);
	ft_freearray(m_envp);
	minishell_exit(126);
}
