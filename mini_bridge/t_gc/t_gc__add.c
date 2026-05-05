/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:12:38 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/05 17:30:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Add front m_node. */
/* Fewer operations avoiding "while()" iterator */
void	t_gc__add(t_gc *m_node)
{
	t_gc	**m_list;
	t_gc	*old_first_node;

	m_list = t_gc__singleton();
	if (*m_list == NULL)
		return (*m_list = m_node, (void) 0);
	old_first_node = *m_list;
	*m_list = m_node;
	m_node->next = old_first_node;
	old_first_node->prev = m_node;
}
