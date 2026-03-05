/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list__extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:17:29 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/28 17:43:43 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*t_list__extract(t_list **lst, void *ptr)
{
	t_list	*node;
	t_list	*prev;

	if (!lst || !*lst)
		return (NULL);
	node = *lst;
	prev = NULL;
	while (node != NULL)
	{
		if (node->value == ptr)
		{
			if (prev != NULL)
				return (prev->next = node->next, node);
			else
				return (*lst = node->next, node);
		}
		prev = node;
		node = node->next;
	}
	return (NULL);
}
