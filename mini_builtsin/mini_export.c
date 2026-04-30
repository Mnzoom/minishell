/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:53:00 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 17:36:11 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_export/mini_export__internal.h"

static int	_is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || (!ft_isalpha(str[i]) && str[i] != '_'))
		return (0);
	i++;
	while ((str[i] && str[i] != '='))
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	mini_export(char **args, t_env **m_env_list, int fd)
{
	size_t	i;
	int		status;

	if (args[1] == NULL)
		return (handle_env_sorted_print(*m_env_list, fd));
	i = 1;
	status = 0;
	while (args[i] != NULL)
	{
		if (!_is_valid_identifier(args[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			status = 1;
		}
		else if (handle_env_export(m_env_list, args[i]) == 1)
			status = 1;
		i++;
	}
	return (status);
}
