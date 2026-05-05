/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list__contains.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:49:42 by anton             #+#    #+#             */
/*   Updated: 2026/02/23 13:38:57 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	t_list__contains(t_list *lst, void *value)
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		if (node->value == value)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}
