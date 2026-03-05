/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list__s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:15:45 by thantoni          #+#    #+#             */
/*   Updated: 2026/02/23 13:38:46 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*t_list__s(t_list *list)
{
	if (list == NULL || list->value == NULL)
		return (NULL);
	return ((char *) list->value);
}
