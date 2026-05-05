/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__print_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:30:37 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:06:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_env__print_all(t_env *m_env_list)
{
	t_env	*m_env;

	m_env = m_env_list;
	while (m_env != NULL)
	{
		t_env__print(m_env);
		m_env = m_env->next;
	}
}
