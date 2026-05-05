/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:16:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/05 16:53:57 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	t_env__free(t_env *m_env)
{
	if (m_env == NULL)
		return ;
	if (m_env->m_key != NULL)
		t_gc__free1(m_env->m_key);
	if (m_env->m_val != NULL)
		t_gc__free1(m_env->m_val);
	t_gc__free1(m_env);
}
