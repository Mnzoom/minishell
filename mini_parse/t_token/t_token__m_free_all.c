/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__m_free_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:08:12 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:04:13 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_token__m_free_all(t_token *m_token_list, int destroy_value)
{
	t_token	*m_token;
	t_token	*to_del;

	m_token = m_token_list;
	while (m_token != NULL)
	{
		to_del = m_token;
		m_token = m_token->next;
		t_token__m_free(to_del, destroy_value);
	}
}
