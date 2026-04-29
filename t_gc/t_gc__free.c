/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:25:43 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 10:54:03 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Free's "t_gc *node" + "void *ptr" */
/* return's NOTHING */
void	t_gc__free0(t_gc *m_node)
{
	if (m_node == NULL)
		return ;
	if (m_node->ptr != NULL)
		free(m_node->ptr);
	free(m_node);
}

/* Looks for ptr inside GC */
/* Free's "t_gc *node" + "void *ptr" */
/* return's NOTHING */
void	t_gc__free1(t_gc **m_list, void *ptr)
{
	t_gc	*node;

	node = *m_list;
	while (node != NULL)
	{
		if (node->ptr == ptr)
		{
			t_gc__free0(node);
			return ;
		}
		node = node->next;
	}
}