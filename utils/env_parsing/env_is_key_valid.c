/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_is_key_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:44:54 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:01:42 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/env_parsing.h"
#include "libft.h"

int	env_is_key_valid(char *key)
{
	int	i;

	if (key == NULL || !key[0] || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (FALSE);
	i = 1;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
