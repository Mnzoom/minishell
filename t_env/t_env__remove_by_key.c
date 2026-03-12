/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__remove_by_key.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:50:04 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/12 11:48:26 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	t_env__remove_by_key(t_env **m_env_list, char *key)
{
	t_env	*m_env;
	size_t	key_len;

	if (!m_env_list || !*m_env_list || !key)
		return ;
	m_env = *m_env_list;
	key_len = ft_strlen(key);
	while (m_env != NULL)
	{
		if (ft_strncmp(m_env->m_key, key, key_len) == 0 && m_env->m_key[key_len] == '\0')
		{
			if (m_env->prev != NULL)
				m_env->prev->next = m_env->next;
			else
				*m_env_list = m_env->next;
			if (m_env->next != NULL)
				m_env->next->prev = m_env->prev;
			t_env__free(m_env);
			return ;
		}
		m_env = m_env->next;
	}
}