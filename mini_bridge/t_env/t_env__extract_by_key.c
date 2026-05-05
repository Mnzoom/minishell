/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__extract_by_key.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:45:30 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/11 15:48:30 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_env	*t_env__extract_by_key(t_env *m_env_list, char *key)
{
	t_env	*m_env;

	m_env = m_env_list;
	while (m_env != NULL)
	{
		if (ft_strncmp(m_env->m_key, key, ft_strlen(key)) == 0)
		{
			m_env->prev->next = m_env->next;
			m_env->next->prev = m_env->prev;
			return (m_env);
		}
		m_env = m_env->next;
	}
	return (NULL);
}
