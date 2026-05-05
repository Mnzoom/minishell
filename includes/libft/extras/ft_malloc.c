/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:15:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/11 18:18:13 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_malloc(void **holder, size_t data_size)
{
	char	*m;

	m = malloc(data_size + 1);
	if (m != NULL)
		m[data_size] = '\0';
	*holder = (void *)m;
	return ((void *)m);
}
