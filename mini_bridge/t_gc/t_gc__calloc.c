/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:16:31 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 03:02:53 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

/* Calloc data and put it in the GC list (malloc associated GC node )*/
/* returns malloc'ed data */
void	*t_gc__calloc(size_t nmemb, size_t size)
{
	void	*m_data;

	m_data = ft_calloc(nmemb, size);
	if (m_data == NULL)
		return (NULL);
	t_gc__m_new(m_data);
	return (m_data);
}
