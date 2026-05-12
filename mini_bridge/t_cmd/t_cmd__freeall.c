/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd__freeall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:05:15 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 07:09:57 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cmd.h"

void	t_cmd__freeall(t_cmd *m_cmd_list)
{
	t_cmd	*m_node;
	t_cmd	*m_to_free;

	m_node = m_cmd_list;
	while (m_node != NULL)
	{
		m_to_free = m_node;
		m_node = m_node->next;
		t_cmd__free(m_to_free);
	}
}
