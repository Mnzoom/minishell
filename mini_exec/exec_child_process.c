/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:48:28 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/06 13:09:00 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

void	exec_child_process(t_cmd *cmd, t_env *m_env_list)
{
	char	*m_path;
	char	**m_envp;

	if (apply_redirections(cmd->m_redirect_list) == -1)
		minishell_exit(1);
	if (!cmd->m_args || !cmd->m_args[0] || cmd->m_args[0][0] == '\0')
		minishell_exit(0);
	if (is_builtin(cmd->m_args[0]))
		return (exec_builtin(cmd, &m_env_list), minishell_exit(0), (void) 0);
	m_path = get_m_path(cmd->m_args[0], m_env_list);
	if (!m_path || access(m_path, F_OK) == -1)
		return (ft_puterr2(PRE_OUT, cmd->m_args[0], ERR_NFOUND), minishell_exit(127));
	if (access(m_path, X_OK) == -1)
		return (ft_puterr(PRE_OUT), perror(cmd->m_args[0]), minishell_exit(126));
	m_envp = t_env__to_m_array(m_env_list);
	execve(m_path, cmd->m_args, m_envp);
	ft_puterr(PRE_OUT);
	perror(cmd->m_args[0]);
	free(m_path);
	ft_freearray(m_envp);
	minishell_exit(126);
}
