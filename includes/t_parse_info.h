/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_info.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 04:19:26 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 07:07:05 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PARSE_INFO_H
# define T_PARSE_INFO_H

# include <stddef.h>

typedef struct s_parse_info
{
	size_t	raw_i;
	size_t	exp_i;
	int		in_single;
	int		in_double;
	int		has_quotes;
	int		rm_quotes;
	int		is_exp;
}	t_parse_info;

t_parse_info	t_parse_info__init(int is_exp, int rm_quotes);

#endif