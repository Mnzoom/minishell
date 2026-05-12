/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:16:31 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 03:02:57 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stddef.h>
#include <stdlib.h>

/* Malloc data and put it in the GC list (malloc associated GC node )*/
/* returns malloc'ed data */
void	*t_gc__malloc(size_t data_size)
{
	void	*m_data;

	m_data = malloc(data_size);
	if (m_data == NULL)
		return (NULL);
	t_gc__m_new(m_data);
	return (m_data);
}
