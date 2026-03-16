/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:28:37 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:52 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	t_env__print(t_env *m_env)
{
	if (m_env == NULL)
		return ;
	printf("\n--------------- ENV --------------\n");
	if (m_env->m_key != NULL)
		printf("key: %s\n", m_env->m_key);
	if (m_env->m_val != NULL)
		printf("val: %s\n", m_env->m_val);
}
