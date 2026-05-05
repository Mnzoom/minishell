/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_extract_m_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:32:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/05 17:00:01 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_gc.h"

char	*env_extract_m_key(char *env_var)
{
	size_t	key_len;
	size_t	cpy_i;
	char	*m_key;

	key_len = 0;
	while (env_var[key_len] && env_var[key_len] != '=')
		key_len++;
	m_key = t_gc__malloc(sizeof(char) * (key_len + 1));
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

char	*env_extract_m_key1(char *env_var, size_t *return_key_len)
{
	size_t	key_len;
	size_t	cpy_i;
	char	*m_key;

	key_len = 0;
	while (env_var[key_len] && env_var[key_len] != '=')
		key_len++;
	m_key = t_gc__malloc(sizeof(char) * (key_len + 1));
	if (m_key == NULL)
		return (*return_key_len = key_len, NULL);
	m_key[key_len] = '\0';
	cpy_i = 0;
	while (env_var[cpy_i] && env_var[cpy_i] != '=')
	{
		m_key[cpy_i] = env_var[cpy_i];
		cpy_i++;
	}
	*return_key_len = key_len;
	return (m_key);
}
