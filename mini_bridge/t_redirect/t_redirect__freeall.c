/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redirect__freeall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:46:45 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 03:02:22 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_redirect.h"
#include <stdlib.h>

void	t_redirect__freeall(t_redirect *m_redirect_list)
{
	t_redirect	*m_node;
	t_redirect	*m_to_free;

	m_node = m_redirect_list;
	while (m_node != NULL)
	{
		m_to_free = m_node;
		m_node = m_node->next;
		t_redirect__free(m_to_free);
	}
}
