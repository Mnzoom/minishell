/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:02:10 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 11:23:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Iterate to find ptr associated GC node */
/* returns found node */
t_gc	*t_gc__get(t_gc **m_list, void *ptr)
{
	t_gc *m_node;

	m_node = *m_list;
	while (m_node != NULL)
	{
		if (m_node->ptr == ptr)
			return (m_node);
		m_node = m_node->next;
	}
	return (NULL);
}