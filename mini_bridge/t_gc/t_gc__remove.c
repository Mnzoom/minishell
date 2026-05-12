/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:56:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 07:10:38 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Simply removes a GC node from GC */
/* DOES NOT FREE */
void	t_gc__remove(t_gc *to_remove)
{
	t_gc	**m_list;

	if (to_remove == NULL)
		return ;
	m_list = t_gc__singleton();
	if (*m_list == to_remove)
		*m_list = to_remove->next;
	if (to_remove->prev != NULL)
		to_remove->prev->next = to_remove->next;
	if (to_remove->next != NULL)
		to_remove->next->prev = to_remove->prev;
	to_remove->prev = NULL;
	to_remove->next = NULL;
}
