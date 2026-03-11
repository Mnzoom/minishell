/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:55:42 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/11 14:36:14 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	_is_flag(char *arg)
{
	size_t	i;

	if (arg == NULL || arg[0] != '-' || arg[1] != 'n')
		return (FALSE);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	mini_echo(char **args, int fd)
{
	size_t	i;
	int		put_new_line;

	i = 1;
	put_new_line = TRUE;
	while (args[i] != NULL && _is_flag(args[i]))
	{
		put_new_line = FALSE;
		i++;
	}
	while (args[i] != NULL)
	{
		ft_putstr_fd(args[i], fd);
		if (args[i + 1] != NULL)
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (put_new_line)
		ft_putstr_fd("\n", fd);
	return (0);
}