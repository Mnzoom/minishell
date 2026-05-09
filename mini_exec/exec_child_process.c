/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:48:28 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/09 07:36:59 by thantoni         ###   ########.fr       */
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
		minishell_exit(1);
	if (!m_cmd_list->m_args || !m_cmd_list->m_args[0] || m_cmd_list->m_args[0][0] == '\0')
		minishell_exit(0);
	if (is_builtin(m_cmd_list->m_args[0]))
		return (exec_builtin(m_cmd_list, &m_env_list), minishell_exit(0), (void) 0);
	if (ft_strchr(m_cmd_list->m_args[0], '/'))
	{
		if (access(m_cmd_list->m_args[0], F_OK) == -1)
			return (perror(m_cmd_list->m_args[0]), minishell_exit(127));
		stat(m_cmd_list->m_args[0], &path_stat);
		if (S_ISDIR(path_stat.st_mode))
		{
			ft_puterr2(PRE_OUT, m_cmd_list->m_args[0], ": Is a directory\n");
			minishell_exit(126);
		}
		m_path = m_cmd_list->m_args[0];
	}
	else
	{
		m_path = get_m_path(m_cmd_list->m_args[0], m_env_list);
		if (!m_path)
			return (ft_puterr2(PRE_OUT, m_cmd_list->m_args[0], ": command not found\n"), minishell_exit(127));
	}
	if (access(m_path, X_OK) == -1)
		return (perror(m_cmd_list->m_args[0]), minishell_exit(126));
	m_envp = t_env__to_m_array(m_env_list);
	execve(m_path, m_cmd_list->m_args, m_envp);
	perror(m_cmd_list->m_args[0]);
	minishell_exit(126);
}
