/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:14:27 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/09 06:57:45 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

static t_token	*_get_current_token(char *m_line)
{
	if (m_line[0] == '>' && m_line[1] == '>')
		return (t_token__m_new(m_line, 2, APPEND));
	if (m_line[0] == '<' && m_line[1] == '<')
		return (t_token__m_new(m_line, 2, HEREDOC));
	if (m_line[0] == '|')
		return (t_token__m_new(m_line, 1, PIPE));
	if (m_line[0] == '>')
		return (t_token__m_new(m_line, 1, OVERRIDE));
	if (m_line[0] == '<')
		return (t_token__m_new(m_line, 1, INFILE));
	return (t_token__parse_value_str(m_line));
}

t_token	*tokenize(char *m_line)
{
	size_t	i;
	t_token	*m_first;
	t_token	*m_last;
	t_token	*m_node;

	i = 0;
	m_first = NULL;
	m_last = NULL;
	while (m_line[i])
	{
		while (m_line[i] == ' ' || m_line[i] == '\t')
			i++;
		if (m_line[i] == '\0' || m_line[i] == '\n' || m_line[i] == '\r')
			break ;
		m_node = _get_current_token(&m_line[i]);
		if (m_node == NULL)
			return (t_token__m_free_all(m_first), NULL);
		if (m_first == NULL)
			m_first = m_node;
		else
		{
			m_node->prev = m_last;
			m_last->next = m_node;
		}
		m_last = m_node;
		i += m_node->raw_len;
	}
	return (m_first);
}
