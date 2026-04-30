/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:05:45 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 18:55:12 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "mini_exec.h"
#include "mini_builtsin.h"

int	mini_exec(t_cmd *cmd_list, t_env **env_list)
{
	int	status;
	int	save_stdout;
	int	save_stdin;

	status = 0;
	if (!cmd_list || !cmd_list->m_args || !cmd_list->m_args[0])
		return (0);

	if (cmd_list && !cmd_list->next && is_builtin(cmd_list->m_args[0]))
	{
		save_stdout = dup(STDOUT_FILENO);
		save_stdin = dup(STDIN_FILENO);
		apply_redirections(cmd_list->m_redirect_list);
		status = exec_builtin(cmd_list, env_list);
		dup2(save_stdout, STDOUT_FILENO);
		dup2(save_stdin, STDIN_FILENO);
		close(save_stdout);
		close(save_stdin);
	}
	else
		status = exec_pipe(cmd_list, *env_list);
	return (status);
}
