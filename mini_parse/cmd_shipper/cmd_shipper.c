/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_shipper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:46:53 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 04:39:05 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

size_t	_get_args_count(t_token *m_token_list)
{
	t_token	*m_token;
	size_t	arg_count;

	m_token = m_token_list;
	arg_count = 0;
	while (m_token != NULL)
	{
		if (m_token->type == PIPE)
			break ;
		if (t_token_type__is_redirection(m_token->type))
			m_token = m_token->next->next;
		else
		{
			if (!m_token->is_ignored)
				arg_count++;
			m_token = m_token->next;
		}
	}
	return (arg_count);
}

t_token	*_pipe_new_cmd(t_token *m_token, t_cmd **m_cmd, size_t *args_i)
{
	(*m_cmd)->next = t_cmd__m_new(_get_args_count(m_token->next));
	*m_cmd = (*m_cmd)->next;
	*args_i = 0;
	return (m_token->next);
}

static t_token	*_ship_token(t_token *m_token, t_cmd **m_cmd, size_t *args_i)
{
	if (m_token->is_ignored)
		return (m_token->next);
	if (t_token_type__is_redirection(m_token->type))
		return (t_cmd__add_m_redirect(*m_cmd, m_token));
	if (m_token->type == PIPE)
		return (_pipe_new_cmd(m_token, m_cmd, args_i));
	(*m_cmd)->m_args[(*args_i)++] = t_gc__strdup(m_token->m_value);
	return (m_token->next);
}

t_cmd	*cmd_shipper(t_token *m_token_list)
{
	t_cmd	*m_cmd_list;
	t_cmd	*m_cmd;
	t_token	*m_token;
	size_t	args_i;

	m_token = m_token_list;
	m_cmd_list = t_cmd__m_new(_get_args_count(m_token));
	m_cmd = m_cmd_list;
	args_i = 0;
	while (m_token != NULL)
		m_token = _ship_token(m_token, &m_cmd, &args_i);
	return (m_cmd_list);
}
