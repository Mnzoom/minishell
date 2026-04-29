/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:12:38 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 10:53:48 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Add front the "gc node". Fewer operations avoiding "while()" iterator*/
/* returns NOTHING */
void	t_gc__add(t_gc **m_list, t_gc *m_node)
{
	t_gc	*first_node;
	
	if (*m_list == NULL)
		return (m_list = m_node, (void) 0);
	first_node = *m_list;
	m_node->next = first_node;
	*m_list = m_node;
}