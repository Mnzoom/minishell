/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:05:58 by cn-goie           #+#    #+#             */
/*   Updated: 2026/04/30 17:34:55 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_exec.h"

extern int g_lastsignal;

int	mini_exit(char **args)
{
	int	i;

	ft_putendl_fd("exit", 1);
	if (!args[1])
		exit(g_lastsignal);
	i = 0;
	if (args[1][i] == '+' || args[1][i] == '-')
		i++;
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			exit(2);
		}
		i++;
	}
	if (args[2])
		return (ft_putendl_fd("minishell: exit: too many arguments", 2), 1);
	exit(ft_atoi(args[1]));
	return (0);
}
