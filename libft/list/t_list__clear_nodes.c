/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list__clear_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:27:58 by anton             #+#    #+#             */
/*   Updated: 2026/01/24 17:29:31 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "stdlib.h"

void	t_list__clear_nodes(t_list **list)
{
	t_list	*curr;
	t_list	*next;

	if (!list || !*list)
		return ;
	curr = *list;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*list = NULL;
}
