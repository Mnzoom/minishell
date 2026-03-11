/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd__add_m_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:19:42 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/10 14:45:12 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

/** Adds a redirect from tokens. 
 * Uses token (redir) + token->next (filename).
 * @return token->next->next.
*/
t_token	*t_cmd__add_m_redirect(t_cmd *m_cmd, t_token *m_token)
{
	t_redirect	*m_redirect;
	t_redirect	*m_to_add;

	m_redirect = m_cmd->m_redirect_list;
	m_to_add = t_redirect__m_new(m_token->next->m_value, m_token->type);
	if (m_redirect == NULL)
		return (m_cmd->m_redirect_list = m_to_add, m_token->next->next);
	while (m_redirect->next != NULL)
		m_redirect = m_redirect->next;
	m_redirect->next = m_to_add;
	return (m_token->next->next);
}
