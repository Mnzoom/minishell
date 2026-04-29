/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:16:31 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 10:54:03 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stddef.h>

/*create a "gc node" on the heap, hold "void *" of the malloc requested */
/* return's (malloc(data_size)); */
void	*t_gc__malloc(t_gc **m_list, size_t data_size)
{
	t_gc	*m_node;
	void	*m_data;

	m_data = malloc(data_size);
	if (m_data == NULL)
	{
		
		return (NULL);
	}
	m_node = t_gc__m_new(m_data);
	t_gc__add(m_list, m_node);
	return (m_data);
}