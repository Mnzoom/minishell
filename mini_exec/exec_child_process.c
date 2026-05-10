/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:48:28 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/10 07:39:55 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

void	exec_child_process(t_cmd *m_cmd_list, t_env *m_env_list)
{
	char		*m_path;
	char		**m_envp;
	struct stat	path_stat;

	if (apply_redirections(m_cmd_list->m_redirect_list) == -1)
		return (t_env__free_all(m_env_list), minishell_exit(1), (void) 0);
	if (!m_cmd_list->m_args || !m_cmd_list->m_args[0])
		return (t_env__free_all(m_env_list), minishell_exit(0), (void) 0);
	if (is_builtin(m_cmd_list->m_args[0]))
		return (exec_builtin(m_cmd_list, &m_env_list), t_env__free_all(m_env_list), minishell_exit(0), (void) 0);
	if (ft_strchr(m_cmd_list->m_args[0], '/'))
	{
		if (access(m_cmd_list->m_args[0], F_OK) == -1)
			return (perror(m_cmd_list->m_args[0]), t_env__free_all(m_env_list), minishell_exit(127), (void) 0);
		stat(m_cmd_list->m_args[0], &path_stat);
		if (S_ISDIR(path_stat.st_mode))
		{
			ft_puterr2(PRE_OUT, m_cmd_list->m_args[0], ": Is a directory\n");
			return (t_env__free_all(m_env_list), minishell_exit(126), (void) 0);
		}
		m_path = m_cmd_list->m_args[0];
	}
	else
	{
		m_path = get_m_path(m_cmd_list->m_args[0], m_env_list);
		if (!m_path)
			return (ft_puterr2(PRE_OUT, m_cmd_list->m_args[0], ": command not found\n"), t_env__free_all(m_env_list), minishell_exit(127), (void) 0);
	}
	if (access(m_path, F_OK) == -1)
		return (perror(m_cmd_list->m_args[0]), t_env__free_all(m_env_list), minishell_exit(127), (void) 0);
	if (access(m_path, X_OK) == -1)
		return (perror(m_cmd_list->m_args[0]), t_env__free_all(m_env_list), minishell_exit(126), (void) 0);
	m_envp = t_env__to_m_array(m_env_list);
	execve(m_path, m_cmd_list->m_args, m_envp);
	perror(m_cmd_list->m_args[0]);
	ft_freearray(m_envp);
	t_env__free_all(m_env_list);
	minishell_exit(126);
}
