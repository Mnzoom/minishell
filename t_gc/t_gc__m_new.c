/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__m_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:09:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 10:53:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Malloc's "t_gc *node" and attach the "void *ptr" at init*/
/* return's (t_gc * node)*/
t_gc	*t_gc__m_new(void *ptr)
{
	t_gc	*node;

	node = malloc(sizeof(t_gc));
	if (node == NULL)
		return (NULL);
	node->ptr = ptr;
	node->next = NULL;
	return (node);
}
