/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__m_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:55:54 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/11 15:44:44 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*_skip_key(char *env_var)
{
	size_t	i;
	
	i = 0;
	while (env_var[i] && env_var[i] != '=')
		i++;
	if (env_var[i] == '=')
		i++;
	return (&env_var[i]);
}

char	*_extract_m_value(char *env_var)
{
	size_t	val_len;
	size_t	cpy_i;
	char	*m_val;

	env_var = _skip_key(env_var);
	val_len = 0;
	while (env_var[val_len])
		val_len++;
	m_val = malloc(sizeof(char) * (val_len + 1));
	if (m_val == NULL)
		return (NULL);
	m_val[val_len] = '\0';
	cpy_i = 0;
	while (env_var[cpy_i])
	{
		m_val[cpy_i] = env_var[cpy_i];
		cpy_i++;
	}
	return (m_val);
}

char	*_extract_m_key(char *env_var)
{
	size_t	key_len;
	size_t	cpy_i;
	char	*m_key;

	key_len = 0;
	while (env_var[key_len] && env_var[key_len] != '=')
		key_len++;
	m_key = malloc(sizeof(char) * (key_len + 1));
	if (m_key == NULL)
		return (NULL);
	m_key[key_len] = '\0';
	cpy_i = 0;
	while (env_var[cpy_i] && env_var[cpy_i] != '=')
	{
		m_key[cpy_i] = env_var[cpy_i];
		cpy_i++;
	}
	return (m_key);
}

t_env	*t_env__m_new(char *env_var)
{
	t_env	*m_env;

	if (env_var == NULL)
		return (NULL);
	m_env = malloc(sizeof(t_env));
	if (m_env == NULL)
		return (NULL);
	m_env->m_key = _extract_m_key(env_var);
	m_env->m_val = _extract_m_value(env_var);
	m_env->next = NULL;
	m_env->prev = NULL;
	return (m_env);
}