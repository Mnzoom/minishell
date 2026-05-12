/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_info__init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:00:00 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 05:28:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_parse_info.h"

t_parse_info	t_parse_info__init(int is_exp, int rm_quotes)
{
	t_parse_info	info;

	info = (t_parse_info){0};
	info.is_exp = is_exp;
	info.rm_quotes = rm_quotes;
	return (info);
}
