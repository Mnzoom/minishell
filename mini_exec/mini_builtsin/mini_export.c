/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:53:00 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 14:38:09 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_export__internal.h"

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
		if (args[i][0] == '-')
		{
			ft_puterr3(PRE_OUT, "export: ", args[i], ": invalid option\n");
			status = 2;
		}
		else if (!_is_valid_identifier(args[i]))
		{
			ft_puterr3(PRE_OUT, "export: `", args[i], \
				"': not a valid identifier\n");
			status = 1;
		}
		else if (handle_env_export(m_env_list, args[i]) == 1)
			status = 1;
		i++;
	}
	return (status);
}
