/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:54:41 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/30 19:03:40 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

#include "mini_builtsin.h"

int	exec_builtin(t_cmd *cmd, t_env **env_list)
{
	char	*name;

	name = cmd->m_args[0];
	if (ft_strcmp(name, "echo") == FALSE)
		return (mini_echo(cmd->m_args));
	if (ft_strcmp(name, "cd") == FALSE)
		return (mini_cd(cmd->m_args, env_list));
	if (ft_strcmp(name, "pwd") == FALSE)
		return (mini_pwd(*env_list));
	if (ft_strcmp(name, "export") == FALSE)
		return (mini_export(cmd->m_args, env_list, 1));
	if (ft_strcmp(name, "unset") == FALSE)
		return (mini_unset(cmd->m_args, env_list));
	if (ft_strcmp(name, "env") == FALSE)
		return (builtin_env(*env_list));
	if (ft_strcmp(name, "exit") == FALSE)
		return (mini_exit(cmd->m_args));
	return (EXIT_FAILURE);
}
