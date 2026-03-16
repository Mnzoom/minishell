/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:47:25 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 15:50:52 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

size_t	get_var_name_len(char *var_name)
{
	size_t	i;

	i = 0;
	while (var_name[i] && ft_isalnum(var_name[i]))
		i++;
	return (i);
}
