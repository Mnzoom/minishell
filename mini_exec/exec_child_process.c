/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:48:28 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/30 20:17:23 by thantoni         ###   ########.fr       */
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
		return (exec_builtin(cmd, &m_env_list), exit(0), (void) 0);
	path = get_path(cmd->m_args[0], m_env_list);
	if (!path || access(path, F_OK) == -1)
		return (ft_puterr2(PRE_OUT, cmd->m_args[0], ERR_NFOUND), exit(127));
	if (access(path, X_OK) == -1)
		return (ft_puterr(PRE_OUT), perror(cmd->m_args[0]), exit(126));
	envp = t_env__to_array(m_env_list);
	execve(path, cmd->m_args, envp);
	ft_puterr(PRE_OUT);
	perror(cmd->m_args[0]);
	exit(126);
}
