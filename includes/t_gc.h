/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:06:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/05 16:17:06 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GC_H
# define T_GC_H

# include <stddef.h>

/* GC stands for "Garbage Collected" */
typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
	struct s_gc	*prev;
}	t_gc;

t_gc	**t_gc__singleton(void);
t_gc	*t_gc__m_new(void *attached_data);
t_gc	*t_gc__get(void *ptr);
t_gc	*t_gc__extract(void *ptr);
void	t_gc__add(t_gc *m_node);
void	t_gc__remove(t_gc *to_remove);

void	t_gc__freeall(void);
void	t_gc__free0(t_gc *m_node);
void	t_gc__free1(void *ptr);

void	*t_gc__malloc(size_t data_size);
void	*t_gc__calloc(size_t nmemb, size_t size);
char	*t_gc__strdup(const char *s);

#endif