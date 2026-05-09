/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredocs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:33:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/09 07:33:35 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"
#include "mini_parse.h"
#include <sys/ioctl.h>

extern int g_lastsignal;

static char	*_expand_heredoc_line(char *m_line, t_env *m_env)
{
	t_token	m_tmp;
	char	*m_exp_line;

	if (!m_line || !ft_strchr(m_line, '$'))
		return (m_line);
	ft_bzero(&m_tmp, sizeof(t_token));
	m_tmp.raw = m_line;
	m_tmp.raw_len = ft_strlen(m_line);
	compute_modifs_len(&m_tmp, m_env, 1, 0);
	handle_modifs(&m_tmp, m_env, 1, 0);
	m_exp_line = ft_strdup(m_tmp.m_value);
	free(m_tmp.m_value);
	free(m_line);
	return (m_exp_line);
}

static char	*_get_line(int is_interacting)
{
	char	*m_line;
	size_t	len;

	if (is_interacting)
		return (readline("> "));
	m_line = get_next_line(STDIN_FILENO);
	if (!m_line)
		return (NULL);
	len = ft_strlen(m_line);
	if (len > 0 && m_line[len - 1] == '\n')
		m_line[len - 1] = '\0';
	len = ft_strlen(m_line);
	if (len > 0 && m_line[len - 1] == '\r')
		m_line[len - 1] = '\0';
	return (m_line);
}

static void	_heredoc(t_redirect *m_red, t_line_input *input, int start_i, t_env *m_env_list, int tmp_fd)
{
	char	*m_line;
	int		is_interactive;
	int		found;
	int		line_count;

	line_count = 1;
	found = 0;
	is_interactive = isatty(STDIN_FILENO);
	rl_catch_signals = 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	if (input)
	{
		while (start_i < input->count)
		{
			m_line = ft_strdup(input->m_lines[start_i++]);
			if (ft_strcmp(m_line, m_red->m_value) == 0)
			{
				free(m_line);
				found = 1;
				break ;
			}
			if (!m_red->had_quotes)
				m_line = _expand_heredoc_line(m_line, m_env_list);
			ft_putendl_fd(m_line, tmp_fd);
			line_count++;
			free(m_line);
		}
	}
	while (!found)
	{
		m_line = _get_line(is_interactive);
		if (!m_line)
		{
			ft_puterr(PRE_OUT);
			ft_puterr("warning: here-document at line ");
			ft_putnbr_fd(line_count, 2);
			ft_puterr(" delimited by end-of-file (wanted `");
			ft_puterr(m_red->m_value);
			ft_puterr("')\n");
			break ;
		}
		if (ft_strcmp(m_line, m_red->m_value) == 0)
		{
			free(m_line);
			break ;
		}
		if (!m_red->had_quotes)
			m_line = _expand_heredoc_line(m_line, m_env_list);
		ft_putendl_fd(m_line, tmp_fd);
		line_count++;
		free(m_line);
	}
	close(tmp_fd);
	minishell_exit(0);
}

static int	_setup_heredoc(t_redirect *m_red, t_line_input *input, int start_i, t_env *m_env_list)
{
	static int	i = 0;
	int		pid;
	int		status;
	int		tmp_fd;
	int		fd_rd;
	char	*m_name;
	char	*s_idx;

	s_idx = ft_itoa(i++);
	m_name = ft_strjoin(".heredoc.tmp", s_idx);
	free(s_idx);
	tmp_fd = open(m_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pid = fork();
	if (pid == 0)
		_heredoc(m_red, input, start_i, m_env_list, tmp_fd);
	close(tmp_fd);
	set_sigaction(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	fd_rd = open(m_name, O_RDONLY);
	unlink(m_name);
	free(m_name);
	if (WIFSIGNALED(status))
	{
		if (fd_rd != -1)
			close(fd_rd);
		return (write(1, "\n", 1), -1);
	}
	return (fd_rd);
}

int	handle_heredocs(t_cmd *m_cmd_list, t_env *m_env_list, t_line_input *input)
{
	t_cmd		*m_cmd_node;
	t_redirect	*m_red_node;

	m_cmd_node = m_cmd_list;
	while (m_cmd_node)
	{
		m_red_node = m_cmd_node->m_redirect_list;
		while (m_red_node)
		{
			if (m_red_node->type == HEREDOC)
			{
				int old_idx = 0;
				if (input)
				{
					old_idx = input->current;
					while (input->current < input->count)
					{
						if (ft_strcmp(input->m_lines[input->current], m_red_node->m_value) == 0)
						{
							input->current++;
							break ;
						}
						input->current++;
					}
				}
				m_red_node->heredoc_fd = _setup_heredoc(m_red_node, input, old_idx, m_env_list);
				setup_inputs_signals();
				if (m_red_node->heredoc_fd == -1)
					return (g_lastsignal = 130, -1);
			}
			m_red_node = m_red_node->next;
		}
		m_cmd_node = m_cmd_node->next;
	}
	return (0);
}
