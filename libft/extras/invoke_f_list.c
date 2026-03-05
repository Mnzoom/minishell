/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_f_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:01:59 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/28 17:43:04 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	invoke_f_list(t_list *f_list, void *value)
{
	void	(*f)(void *);

	while (f_list)
	{
		f = (void (*)(void *))f_list->value;
		if (f == NULL)
			continue ;
		f(value);
		f_list = f_list->next;
	}
}
