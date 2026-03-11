/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__get_by_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:39:32 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/11 15:44:12 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_env	*t_env__get_by_key(t_env *m_env_list, char *key)
{
	t_env	*m_env;

	m_env = m_env_list;
	while (m_env != NULL)
	{
		if (ft_strncmp(m_env->m_key, key, ft_strlen(key)) == 0)
			return (m_env);
		m_env = m_env->next;
	}
	return (NULL);
}
