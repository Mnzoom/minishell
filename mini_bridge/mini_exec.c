/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:05:45 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/01 22:22:49 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "mini_exec.h"
#include "mini_builtsin.h"

int	mini_exec(t_cmd *m_cmd_list, t_env **m_env_list)
{
	int	status;
	int	save_stdout;
	int	save_stdin;

	status = 0;
	if (!m_cmd_list || !m_cmd_list->m_args)
		return (0);
	if (m_cmd_list && !m_cmd_list->next && is_builtin(m_cmd_list->m_args[0]))
	{
		save_stdout = dup(STDOUT_FILENO);
		save_stdin = dup(STDIN_FILENO);
		if (apply_redirections(m_cmd_list->m_redirect_list) == -1)
			status = 1;
		else
			status = exec_builtin(m_cmd_list, m_env_list);
		dup2(save_stdout, STDOUT_FILENO);
		dup2(save_stdin, STDIN_FILENO);
		close(save_stdout);
		close(save_stdin);
	}
	else
		status = exec_pipe(m_cmd_list, *m_env_list);
	return (status);
}
