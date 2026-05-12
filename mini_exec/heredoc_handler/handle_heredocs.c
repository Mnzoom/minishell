/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredocs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:33:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/12 08:23:19 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"
#include "mini_parse.h"
#include <sys/ioctl.h>

extern int	g_lastsignal;

static void	_wipe_stdin(char *lim)
{
	char	*to_wipe;
	size_t	to_wipe_len;
	int		is_lim;

	while (TRUE)
	{
		to_wipe = get_next_line(STDIN_FILENO);
		if (!to_wipe)
			break ;
		to_wipe_len = ft_strlen(to_wipe);
		if (to_wipe_len > 0 && to_wipe[to_wipe_len - 1] == '\n')
			to_wipe[to_wipe_len - 1] = '\0';
		to_wipe_len = ft_strlen(to_wipe);
		if (to_wipe_len > 0 && to_wipe[to_wipe_len - 1] == '\r')
			to_wipe[to_wipe_len - 1] = '\0';
		is_lim = (ft_strcmp(to_wipe, lim) == 0);
		free(to_wipe);
		if (is_lim)
			break ;
	}
}

static int	_wait_heredoc_child(t_heredoc_info *info, int pid, char *m_name)
{
	int	status;

	set_sigaction(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (!WIFSIGNALED(status) && !isatty(STDIN_FILENO))
		_wipe_stdin(info->m_red->m_value);
	info->tmp_fd = open(m_name, O_RDONLY);
	unlink(m_name);
	free(m_name);
	if (WIFSIGNALED(status))
	{
		if (info->tmp_fd != -1)
			close(info->tmp_fd);
		return (write(1, "\n", 1), -1);
	}
	return (info->tmp_fd);
}

static int	_execute_heredoc(t_heredoc_info *info)
{
	static int	i = 0;
	int			pid;
	char		*m_name;
	char		*heredoc_id;

	heredoc_id = ft_itoa(i++);
	m_name = ft_strjoin(".heredoc.tmp_", heredoc_id);
	free(heredoc_id);
	info->tmp_fd = open(m_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pid = fork();
	if (pid == 0)
	{
		free(m_name);
		handle_heredocs_child(info);
	}
	close(info->tmp_fd);
	return (_wait_heredoc_child(info, pid, m_name));
}

static void	_sync_input_index(t_heredoc_info *info)
{
	info->start_i = 0;
	if (!info->input)
		return ;
	info->start_i = info->input->current;
	while (info->input->current < info->input->count)
	{
		if (ft_strcmp(info->input->m_lines[info->input->current],
				info->m_red->m_value) == 0)
		{
			info->input->current++;
			break ;
		}
		info->input->current++;
	}
}

int	handle_heredocs(t_cmd *m_cmd_list, t_env *m_env_list, t_line_input *input)
{
	t_cmd			*m_cmd;
	t_redirect		*m_red;
	t_heredoc_info	info;

	m_cmd = m_cmd_list;
	while (m_cmd)
	{
		m_red = m_cmd->m_redirect_list;
		while (m_red)
		{
			if (m_red->type == HEREDOC)
			{
				info = t_heredoc_info__init(m_red, m_env_list, input);
				_sync_input_index(&info);
				m_red->heredoc_fd = _execute_heredoc(&info);
				setup_inputs_signals();
				if (m_red->heredoc_fd == -1)
					return (g_lastsignal = 130, -1);
			}
			m_red = m_red->next;
		}
		m_cmd = m_cmd->next;
	}
	return (0);
}
