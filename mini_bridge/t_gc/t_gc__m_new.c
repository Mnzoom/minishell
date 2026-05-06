/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__m_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:09:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/06 12:30:24 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Mallocs a node struct and initialize it */
/* returns the new node initialized */
t_gc	*t_gc__m_new(void *ptr)
{
	t_gc	*m_node;

	if (ptr == NULL)
		return (NULL);
	m_node = malloc(sizeof(t_gc));
	if (m_node == NULL)
		return (NULL);
	m_node->ptr = ptr;
	m_node->next = NULL;
	m_node->prev = NULL;
	t_gc__add(m_node);
	return (m_node);
}
