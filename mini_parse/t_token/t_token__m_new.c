/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__m_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:40:58 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/09 17:20:41 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

t_token	*t_token__m_new(char *start, size_t len, t_token_type type)
{
	t_token *m_token;

	m_token = malloc(sizeof(t_token));
	if (!m_token)
		return (NULL);
	m_token->raw = start;
	m_token->raw_len = len;
	m_token->m_value = NULL;
	m_token->diff_len = 0;
	m_token->has_diff = FALSE;
	m_token->type = type;
	m_token->next = NULL;
	return (m_token);
}
