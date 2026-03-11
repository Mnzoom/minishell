/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:16:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/11 16:43:16 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_env__free(t_env *m_env)
{
	if (m_env == NULL)
		return ;
	if (m_env->m_key != NULL)
		free(m_env->m_key);
	if (m_env->m_val != NULL)
		free(m_env->m_val);
	free(m_env);
}