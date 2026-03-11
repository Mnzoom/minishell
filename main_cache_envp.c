/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cache_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:10:26 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/11 16:52:38 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*main_cache_envp(char **envp)
{
	t_env	*m_env_list;
	t_env	*m_env;
	size_t	i;

	if (envp == NULL || envp[0] == NULL)
		return (NULL);
	m_env_list = t_env__m_new(envp[0]);
	if (m_env_list == NULL)
		return (t_env__free_all(m_env_list), NULL);
	m_env = m_env_list;
	i = 1;
	while (envp[i])
	{
		m_env->next = t_env__m_new(envp[i]);
		if (m_env->next == NULL)
			return (t_env__free_all(m_env_list), NULL);
		m_env->next->prev = m_env;
		m_env = m_env->next;
		i++;
	}
	return (m_env_list);
}
