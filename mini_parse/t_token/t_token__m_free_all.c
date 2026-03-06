/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__m_free_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:08:12 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 18:58:01 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_token__m_free_all(t_token *m_token)
{
	t_token	*m_token_node;
	t_token	*to_del;
	
	m_token_node = m_token;
	while (m_token_node != NULL)
	{
		to_del = m_token_node;
		m_token_node = m_token_node->next;
		t_token__m_free(to_del);
	}
}
