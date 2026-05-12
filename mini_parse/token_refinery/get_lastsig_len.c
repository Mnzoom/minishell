/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lastsig_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:33:28 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 02:48:28 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

extern int	g_lastsignal;

size_t	get_lastsig_len(void)
{
	int			tmp_lastsignal;
	size_t		len;

	tmp_lastsignal = g_lastsignal;
	len = 0;
	if (tmp_lastsignal == 0)
		return (1);
	if (tmp_lastsignal < 0)
	{
		len++;
		tmp_lastsignal = -tmp_lastsignal;
	}
	while (tmp_lastsignal > 0)
	{
		len++;
		tmp_lastsignal /= 10;
	}
	return (len);
}
