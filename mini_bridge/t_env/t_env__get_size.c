/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__get_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:08:06 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/12 12:24:31 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	t_env__get_size(t_env *m_env_list)
{
	t_env	*m_env;
	size_t	count;

	count = 0;
	m_env = m_env_list;
	while (m_env != NULL)
	{
		count++;
		m_env = m_env->next;
	}
	return (count);
}
