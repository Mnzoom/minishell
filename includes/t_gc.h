/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:06:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/29 10:54:05 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GC_H
# define T_GC_H

/* GC stands for "Garbage Collected" */
typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}	t_gc;

t_gc	*t_gc__m_new(void *attached_data);
void	t_gc__add(t_gc **m_list, t_gc *m_node);
void	*t_gc__malloc(t_gc **m_list, size_t data_size);
void	t_gc__free0(t_gc *m_node);
void	t_gc__free1(t_gc **m_list, void *ptr);
void	t_gc__freeall(t_gc **m_list);

#endif