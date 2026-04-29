/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc__remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:56:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 11:31:05 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_gc.h"
#include <stdlib.h>

/* Simply removes a GC node from GC */
/* DOES NOT FREE */
void	t_gc__remove(t_gc **m_list, t_gc *to_remove)
{
	t_gc__extract(m_list, to_remove->ptr);
}
