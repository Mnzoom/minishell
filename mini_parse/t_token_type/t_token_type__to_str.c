/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_type__to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:26:21 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/09 17:28:41 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

const char	*t_token_type__to_str(t_token_type type)
{
	if (type == 0)
		return ("PIPE");
	if (type == 1)
		return ("OVERRIDE");
	if (type == 2)
		return ("APPEND");
	if (type == 3)
		return ("INFILE");
	if (type == 4)
		return ("HEREDOC");
	if (type == 5)
		return ("STR");
	return ("ERROR_UNDEFINED_TOKEN_TYPE");
}
