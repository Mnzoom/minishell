/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:20:36 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 18:47:37 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mini_export__internal.h"
#include "t_env__internal.h"
#include "libft.h"

int	_print_export_error(char *arg, char *key)
{
	ft_putstr_fd("minishell: export: `", FD_ERR);
	ft_putstr_fd(arg, FD_ERR);
	ft_putstr_fd("': not a valid identifier\n", FD_ERR);
	free(key);
	return (EXIT_ERROR);
}

int	handle_env_export(t_env **m_env_list, char *arg)
{
	char	*key;
	t_env	*found;

	key = env_extract_m_key(arg);
	if (key == NULL)
		return (EXIT_ERROR);
	if (!env_is_key_valid(key))
		return (_print_export_error(arg, key));
	found = t_env__get_by_key(*m_env_list, key);
	if (found != NULL)
	{
		if (ft_strchr(arg, '=') != NULL)
		{
			if (found->m_val != NULL)
				free(found->m_val);
			found->m_val = env_extract_m_value(arg);
		}
	}
	else
		t_env__add_back(m_env_list, t_env__m_new(arg));
	return (free(key), EXIT_SUCCESS);
}
