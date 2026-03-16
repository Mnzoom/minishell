/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__m_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:55:54 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:34:24 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils/env_parsing.h"

t_env	*t_env__m_new(char *env_var)
{
	t_env	*m_env;

	if (env_var == NULL)
		return (NULL);
	m_env = malloc(sizeof(t_env));
	if (m_env == NULL)
		return (NULL);
	m_env->m_key = env_extract_m_key1(env_var, &m_env->key_len);
	if (m_env->m_key == NULL)
		return (t_env__free(m_env), NULL);
	m_env->m_val = env_extract_m_value1(env_var, &m_env->val_len);
	if (m_env->m_val == NULL)
		return (t_env__free(m_env), NULL);
	m_env->next = NULL;
	m_env->prev = NULL;
	return (m_env);
}
