/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd__add_m_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:19:42 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 05:03:01 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

t_token	*t_cmd__add_m_redirect(t_cmd *m_cmd, t_token *m_token)
{
	t_redirect	*m_redirect;
	t_redirect	*m_to_add;

	m_redirect = m_cmd->m_redirect_list;
	m_to_add = t_redirect__m_new(t_gc__strdup(m_token->next->m_value), m_token->type);
	m_to_add->had_quotes = m_token->next->had_quotes;
	if (m_redirect == NULL)
		return (m_cmd->m_redirect_list = m_to_add, m_token->next->next);
	while (m_redirect->next != NULL)
		m_redirect = m_redirect->next;
	m_redirect->next = m_to_add;
	return (m_token->next->next);
}
