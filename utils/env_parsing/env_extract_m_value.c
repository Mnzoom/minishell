/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_extract_m_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:30:49 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 17:26:37 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_parsing.h"
#include <stdlib.h>

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

char	*env_extract_m_value(char *env_var)
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

char	*env_extract_m_value1(char *env_var, size_t *return_val_len)
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
		return (*return_val_len = val_len, NULL);
	m_val[val_len] = '\0';
	cpy_i = 0;
	while (env_var[cpy_i])
	{
		m_val[cpy_i] = env_var[cpy_i];
		cpy_i++;
	}
	*return_val_len = val_len;
	return (m_val);
}
