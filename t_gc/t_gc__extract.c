/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:07:09 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 11:22:55 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Extracts ptr associated GC node */
/* returns found and extracted node */
t_gc	*t_gc__extract(t_gc **m_list, void *ptr)
{
	t_gc	*m_node;

	m_node = t_gc__get(m_list, ptr);
	if (m_node == NULL)
		return (NULL);
	if (m_node->prev != NULL)
		m_node->prev->next = m_node->next;
	if (m_node->next != NULL)
		m_node->next->prev = m_node->prev;
	return (m_node);
}
