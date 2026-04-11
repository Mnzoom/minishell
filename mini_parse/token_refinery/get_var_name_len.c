/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:47:25 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/11 14:10:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

size_t	get_var_name_len(char *var_name)
{
	size_t	i;

	i = 0;
	if (var_name[0] == '\0')
		return (0);
	if (!ft_isalpha(var_name[0]) && var_name[0] != '_')
		return (0);
	i = 1;
	while (var_name[i] && (ft_isalnum(var_name[i]) || var_name[i] == '_'))
		i++;
	return (i);
}
