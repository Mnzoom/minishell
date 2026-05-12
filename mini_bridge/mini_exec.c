/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:05:45 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 07:09:33 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "mini_exec.h"
#include "mini_builtsin.h"

static int	_exec_solo_builtin(t_cmd *m_cmd, t_env **m_env_list)
{
	int	status;
	int	save_stdout;
	int	save_stdin;

	save_stdout = dup(STDOUT_FILENO);
	save_stdin = dup(STDIN_FILENO);
	if (apply_redirections(m_cmd->m_redirect_list) == -1)
		status = 1;
	else
		status = exec_builtin(m_cmd, m_env_list);
	dup2(save_stdout, STDOUT_FILENO);
	dup2(save_stdin, STDIN_FILENO);
	close(save_stdout);
	close(save_stdin);
	return (status);
}

static void	_close_heredocs(t_cmd *m_cmd_list)
{
	t_cmd		*tmp_cmd;
	t_redirect	*tmp_red;

	tmp_cmd = m_cmd_list;
	while (tmp_cmd)
	{
		tmp_red = tmp_cmd->m_redirect_list;
		while (tmp_red)
		{
			if (tmp_red->type == HEREDOC && tmp_red->heredoc_fd != -1)
				close(tmp_red->heredoc_fd);
			tmp_red = tmp_red->next;
		}
		tmp_cmd = tmp_cmd->next;
	}
}

int	mini_exec(t_cmd *m_cmd_list, t_env **m_env_list, t_line_input *input)
{
	int			status;

	status = 0;
	if (!m_cmd_list || !m_cmd_list->m_args)
		return (0);
	if (handle_heredocs(m_cmd_list, *m_env_list, input) == -1)
		return (130);
	if (m_cmd_list && !m_cmd_list->next && is_builtin(m_cmd_list->m_args[0]))
		status = _exec_solo_builtin(m_cmd_list, m_env_list);
	else
		status = exec_pipe(m_cmd_list, *m_env_list);
	_close_heredocs(m_cmd_list);
	return (status);
}
