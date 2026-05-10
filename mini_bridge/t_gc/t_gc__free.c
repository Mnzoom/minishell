/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:25:43 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 00:01:55 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Extract from GC */
/* Frees Node and Ptr */
void	t_gc__free0(t_gc *m_node)
{
	if (m_node == NULL)
		return ;
	if (m_node->ptr != NULL)
		free(m_node->ptr);
	free(m_node);
}

/* Extract from GC */
/* Frees Node and Ptr */
void	t_gc__free1(void *ptr)
{
	t_gc	*m_node;

	if (ptr == NULL)
		return ;
	m_node = t_gc__extract(ptr);
	if (m_node == NULL)
	{
		free(ptr);
		return ;
	}
	if (m_node->ptr != NULL)
	{
		free(m_node->ptr);
		m_node->ptr = NULL;
	}
	free(m_node);
}
