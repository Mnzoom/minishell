/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:54:41 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/10 03:20:27 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"
#include "mini_builtsin.h"

int	exec_builtin(t_cmd *m_cmd, t_env **m_env_list)
{
	char	*m_name;

	m_name = m_cmd->m_args[0];
	if (ft_strcmp(m_name, "echo") == FALSE)
		return (mini_echo(m_cmd->m_args));
	if (ft_strcmp(m_name, "cd") == FALSE)
		return (mini_cd(m_cmd->m_args, m_env_list));
	if (ft_strcmp(m_name, "pwd") == FALSE)
		return (mini_pwd(*m_env_list));
	if (ft_strcmp(m_name, "export") == FALSE)
		return (mini_export(m_cmd->m_args, m_env_list, 1));
	if (ft_strcmp(m_name, "unset") == FALSE)
		return (mini_unset(m_cmd->m_args, m_env_list));
	if (ft_strcmp(m_name, "env") == FALSE)
	{
		if (m_cmd->m_args[1] != NULL)
		{
			ft_puterr3(PRE_OUT, "env: ", m_cmd->m_args[1], ": No such file or directory\n");
			return (127);
		}
		return (builtin_env(*m_env_list));
	}
	if (ft_strcmp(m_name, "exit") == FALSE)
		return (mini_exit(m_cmd->m_args));
	return (EXIT_FAILURE);
}
