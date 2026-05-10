/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:55:42 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 09:35:56 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_exec.h"
#include "libft.h"
#include <stddef.h>

int	mini_echo(char **args)
{
	int	n_flag;
	int	i;
	int	j;

	i = 1;
	n_flag = FALSE;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break ;
		n_flag = TRUE;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1); 
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!n_flag)
		ft_putstr_fd("\n", 1);
	return (0);
}
