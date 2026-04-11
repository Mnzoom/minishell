/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_sorted_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:18:12 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/11 15:46:22 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtsin/mini_export.h"
#include "libft.h"
#include <stdlib.h>

t_env	**_bubble_sort(t_env **m_sort, size_t env_count)
{
	size_t	i;
	size_t	cmp_i;
	t_env	*tmp;

	if (m_sort == NULL)
		return (NULL);
	i = 0;
	while (i < env_count)
	{
		cmp_i = 0;
		while (cmp_i < env_count - i && m_sort[cmp_i + 1])
		{
			if (ft_strcmp(m_sort[cmp_i]->m_key, m_sort[cmp_i + 1]->m_key) > 0)
			{
				tmp = m_sort[cmp_i];
				m_sort[cmp_i] = m_sort[cmp_i + 1];
				m_sort[cmp_i + 1] = tmp;
			}
			cmp_i++;
		}
		i++;
	}
	return (m_sort);
}

t_env	**_create_sort_array(t_env *m_env_list, size_t env_count)
{
	t_env	**m_sort;
	t_env	*m_env;
	size_t	i;

	m_sort = malloc(sizeof(t_env *) * (env_count + 1));
	if (m_sort == NULL)
		return (NULL);
	m_sort[env_count] = NULL;
	m_env = m_env_list;
	i = 0;
	while (i < env_count)
	{
		m_sort[i] = m_env;
		m_env = m_env->next;
		i++;
	}
	return (m_sort);
}

int	handle_env_sorted_print(t_env *m_env_list, int fd)
{
	t_env	**m_sort;
	size_t	env_count;
	size_t	i;

	env_count = t_env__get_size(m_env_list);
	m_sort = _bubble_sort(_create_sort_array(m_env_list, env_count), env_count);
	if (m_sort == NULL)
		return (EXIT_ERROR);
	i = 0;
	while (i < env_count)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(m_sort[i]->m_key, fd);
		if (m_sort[i]->m_val != NULL)
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(m_sort[i]->m_val, fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
		i++;
	}
	return (free(m_sort), EXIT_SUCCESS);
}
