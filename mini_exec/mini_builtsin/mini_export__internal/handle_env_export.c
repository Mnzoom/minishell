/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:20:36 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 04:52:10 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mini_export__internal.h"
#include "t_env__internal.h"
#include "libft.h"

int	_print_export_error(char *arg, char *key)
{
	ft_puterr3(PRE_OUT, "export: `", arg, "': not a valid identifier\n");
	free(key);
	return (EXIT_ERROR);
}

static void	_update_env_val(t_env *m_found, char *arg)
{
	if (ft_strchr(arg, '=') != NULL)
	{
		if (m_found->m_val != NULL)
			t_gc__free1(m_found->m_val);
		m_found->m_val = env_extract_m_value(arg);
		if (m_found->m_val)
			m_found->val_len = ft_strlen(m_found->m_val);
		else
			m_found->val_len = 0;
	}
}

int	handle_env_export(t_env **m_env_list, char *arg)
{
	char	*m_key;
	t_env	*m_found;

	m_key = env_extract_m_key(arg);
	if (m_key == NULL)
		return (EXIT_ERROR);
	if (!env_is_key_valid(m_key))
	{
		t_gc__free1(m_key);
		return (_print_export_error(arg, NULL));
	}
	m_found = t_env__get_by_key(*m_env_list, m_key);
	if (m_found != NULL)
		_update_env_val(m_found, arg);
	else
		t_env__add_back(m_env_list, t_env__m_new(arg));
	return (t_gc__free1(m_key), EXIT_SUCCESS);
}
