/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:07:09 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/06 12:39:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Extracts ptr associated GC node */
/* returns found and extracted node */
t_gc	*t_gc__extract(void *ptr)
{
	t_gc	*m_node;

	if (ptr == NULL)
		return (NULL);
	m_node = t_gc__get(ptr);
	if (m_node == NULL)
		return (NULL);
	t_gc__remove(m_node);
	return (m_node);
}
