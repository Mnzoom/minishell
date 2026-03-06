/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__parse_value_str.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:09:20 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 16:55:06 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

t_token	*t_token__parse_value_str(char *start)
{
	size_t	len;
	int		is_inside_single;
	int		is_inside_double;

	len = 0;
	is_inside_single = 0;
	is_inside_double = 0;
	while (start[len] != '\0')
	{
		if (start[len] == '\'' && is_inside_double == 0)
			is_inside_single = !is_inside_single;
		else if (start[len] == '"' && is_inside_single == 0)
			is_inside_double = !is_inside_double;
		else if (is_inside_single == 0 && is_inside_double == 0)
		{
			if (start[len] == ' ' || start[len] == '\t')
				break;
			if (start[len] == '|' || start[len] == '<' || start[len] == '>')
				break;
		}
		len++;
	}
	if (len == 0)
		return (NULL);
	return (t_token__m_new(start, len, STR));
}