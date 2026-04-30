/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:48:28 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/30 18:08:49 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

void	exec_child_process(t_cmd *cmd, t_env *m_env_list)
{
	char	*path;
	char	**envp;

	if (apply_redirections(cmd->m_redirect_list) == -1)
		exit(1);
	if (!cmd->m_args || !cmd->m_args[0] || cmd->m_args[0][0] == '\0')
		exit(0);
	if (is_builtin(cmd->m_args[0]))
	{
		exec_builtin(cmd, &m_env_list);
		exit(0);
	}
	path = get_path(cmd->m_args[0], m_env_list);
	if (!path || access(path, F_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->m_args[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
	if (access(path, X_OK) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(cmd->m_args[0]);
		exit(126);
	}
	envp = t_env__to_array(m_env_list);
	execve(path, cmd->m_args, envp);
	ft_putstr_fd("minishell: ", 2);
	perror(cmd->m_args[0]);
	exit(126);
}
