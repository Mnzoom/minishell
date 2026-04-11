/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isenvpattern.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:59:22 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/11 15:58:27 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mini_parse.h"

int	ft_isenvpattern(char *str)
{
	if (!str || str[0] != '$' || str[1] == '\0' || str[1] == ' ')
		return (FALSE);
	return (ft_isenvchar(str[1]));
}
