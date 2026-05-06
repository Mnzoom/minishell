/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:05:58 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/05 19:43:31 by thantoni         ###   ########.fr       */
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
		minishell_exit(g_lastsignal);
	i = 0;
	if (args[1][i] == '+' || args[1][i] == '-')
		i++;
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
		{
			ft_puterr3(PRE_OUT, "exit: ", args[1], ": numeric argument required");
			minishell_exit(2);
		}
		i++;
	}
	if (args[2])
		return (ft_puterr1(PRE_OUT, "exit: too many arguments\n"), 1);
	minishell_exit(ft_atoi(args[1]));
	return (0);
}
