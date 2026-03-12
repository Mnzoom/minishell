/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:53:00 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/12 12:24:18 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtsin/mini_export.h"

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
		if (handle_env_export(m_env_list, args[i]) == 1)
			status = 1;
		i++;
	}
	return (status);
}
