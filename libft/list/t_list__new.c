/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list__new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:04:00 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/28 17:43:38 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

t_list	*t_list__new(void *value)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->value = value;
	list->next = NULL;
	return (list);
}
