/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__freeall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:34:45 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 03:03:06 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Iterate GC list and frees every node */
void	t_gc__freeall(void)
{
	t_gc	**m_list;
	t_gc	*m_node;
	t_gc	*to_del;

	m_list = t_gc__singleton();
	m_node = *m_list;
	while (m_node != NULL)
	{
		to_del = m_node;
		m_node = m_node->next;
		t_gc__free0(to_del);
	}
	*m_list = NULL;
}
