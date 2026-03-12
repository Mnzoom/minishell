/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:34:48 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/12 12:39:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_env__add_back(t_env **m_env_list, t_env *to_add)
{
	t_env	*m_env;

	if (*m_env_list == NULL)
	{
		*m_env_list = to_add;
		return ;
	}
	m_env = *m_env_list;
	while (m_env->next != NULL)
		m_env = m_env->next;
	m_env->next = to_add;
	to_add->prev = m_env;
}
