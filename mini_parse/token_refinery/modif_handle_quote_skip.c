/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_handle_quote_skip.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 09:01:12 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 09:19:40 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

size_t	modif_handle_quote_skip(char *raw, int *in_single, int *in_double)
{
	size_t	skip_i;

	skip_i = 0;
	while ((raw[skip_i] == '\'' && !*in_double) || (raw[skip_i] == '\"' && !*in_single))
	{
		if (raw[skip_i] == '\'' && !*in_double)
		{
			while (raw[skip_i] == '\'')
				(*in_single = !*in_single, skip_i++);
		}
		else if (raw[skip_i] == '\"' && !*in_single)
		{
			while (raw[skip_i] == '\"')
				(*in_double = !*in_double, skip_i++);
		}
	}
	return (skip_i);
}
