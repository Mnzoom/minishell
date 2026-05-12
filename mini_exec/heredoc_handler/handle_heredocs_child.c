/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredocs_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 04:06:09 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 07:12:53 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"
#include "mini_parse.h"

static char	*_expand_heredoc_line(char *m_line, t_env *m_env)
{
	t_token	tmp;
	char	*m_exp_line;

	if (!m_line || !ft_strchr(m_line, '$'))
		return (m_line);
	tmp = (t_token){0};
	tmp.raw = m_line;
	tmp.raw_len = ft_strlen(m_line);
	compute_modifs_len(&tmp, m_env, 1, 0);
	handle_modifs(&tmp, m_env, 1, 0);
	m_exp_line = ft_strdup(tmp.m_value);
	free(tmp.m_value);
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

static void	_process_input_lines(t_heredoc_info *info)
{
	char	*m_line;

	if (!info->input)
		return ;
	while (info->start_i < info->input->count)
	{
		m_line = ft_strdup(info->input->m_lines[info->start_i++]);
		if (ft_strcmp(m_line, info->m_red->m_value) == 0)
		{
			free(m_line);
			info->found = 1;
			break ;
		}
		if (!info->m_red->had_quotes)
			m_line = _expand_heredoc_line(m_line, info->m_env);
		ft_putendl_fd(m_line, info->tmp_fd);
		info->l_count++;
		free(m_line);
	}
}

static void	_process_interactive_lines(t_heredoc_info *info)
{
	char	*m_line;

	while (!info->found)
	{
		m_line = _get_line(info->is_int);
		if (!m_line)
		{
			ft_puterr1(PRE_OUT, "warning: here-document at line ");
			ft_putnbr_fd(info->l_count, 2);
			ft_puterr(" delimited by end-of-file (wanted `");
			ft_puterr1(info->m_red->m_value, "')\n");
			break ;
		}
		if (ft_strcmp(m_line, info->m_red->m_value) == 0)
		{
			free(m_line);
			break ;
		}
		if (!info->m_red->had_quotes)
			m_line = _expand_heredoc_line(m_line, info->m_env);
		ft_putendl_fd(m_line, info->tmp_fd);
		info->l_count++;
		free(m_line);
	}
}

void	handle_heredocs_child(t_heredoc_info *info)
{
	info->l_count = 1;
	info->found = 0;
	info->is_int = isatty(STDIN_FILENO);
	rl_catch_signals = 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	_process_input_lines(info);
	_process_interactive_lines(info);
	close(info->tmp_fd);
	if (info->input && info->input->m_lines)
		ft_freearray(info->input->m_lines);
	minishell_exit(0);
}
