/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:02:10 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/05 16:18:48 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Iterate to find ptr associated GC node */
/* returns found node */
t_gc	*t_gc__get(void *ptr)
{
	t_gc	*m_node;

	if (ptr == NULL)
		return (NULL);
	m_node = *t_gc__singleton();
	while (m_node != NULL)
	{
		if (m_node->ptr == ptr)
			return (m_node);
		m_node = m_node->next;
	}
	return (NULL);
}
