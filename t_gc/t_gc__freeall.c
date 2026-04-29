/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__freeall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:34:45 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 11:20:43 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Iterate GC list and frees every node */
void	t_gc__freeall(t_gc **m_list)
{
	t_gc	*node;
	t_gc	*to_del;

	node = *m_list;
	while (node != NULL)
	{
		to_del = node;
		node = node->next;
		t_gc__free0(to_del);
	}
}