/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_eol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:48:34 by thantoni          #+#    #+#             */
/*   Updated: 2026/02/23 13:39:31 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen_eol(char *s, char eol)
{
	size_t	len;

	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == eol)
		len--;
	return (len);
}
