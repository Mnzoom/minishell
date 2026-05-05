/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__free_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:18:10 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:01:05 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_env__free_all(t_env *m_env_list)
{
	t_env	*m_env;
	t_env	*to_free;

	m_env = m_env_list;
	while (m_env != NULL)
	{
		to_free = m_env;
		m_env = m_env->next;
		t_env__free(to_free);
	}
}
