/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_is_key_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:44:54 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/18 13:32:56 by cn-goie          ###   ########.fr       */
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
