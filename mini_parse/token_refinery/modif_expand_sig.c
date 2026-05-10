/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_expand_sig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 08:58:39 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 09:29:51 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

extern int	g_lastsignal;

static size_t	_insert_sig(char *holder)
{
	size_t	len;
	size_t	i;
	long	num;

	num = g_lastsignal;
	len = get_lastsig_len();
	i = len;
	if (num < 0)
	{
		holder[0] = '-';
		num = -num;
	}
	if (num == 0)
		holder[0] = '0';
	while (num > 0)
	{
		i--;
		holder[i] = (num % 10) + '0';
		num = num / 10;
	}
	return (len);
}

void	modif_expand_sig(t_token *m_token, t_parse_info *info)
{
	info->exp_i += _insert_sig(&m_token->m_value[info->exp_i]);
	info->raw_i += 1 + 1;
}
