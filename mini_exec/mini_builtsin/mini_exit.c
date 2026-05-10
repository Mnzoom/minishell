/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:05:58 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/10 03:32:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_exec.h"
#include <limits.h>

extern int g_lastsignal;

static void	_check_overflow(char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (str[i])
	{
		if ((sign == 1 && res > (unsigned long long)LLONG_MAX / 10)
			|| (sign == 1 && res == (unsigned long long)LLONG_MAX / 10
				&& (str[i] - '0') > LLONG_MAX % 10)
			|| (sign == -1 && res > (unsigned long long)LLONG_MAX / 10)
			|| (sign == -1 && res == (unsigned long long)LLONG_MAX / 10
				&& (str[i] - '0') > (LLONG_MAX % 10) + 1))
		{
			ft_puterr3(PRE_OUT, "exit: ", str, ": numeric argument required\n");
			minishell_exit(2);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
}

int	mini_exit(char **args)
{
	int	i;

	// ft_putendl_fd("exit", 1);
	if (!args[1])
		minishell_exit(g_lastsignal);
	i = 0;
	if (args[1][i] == '+' || args[1][i] == '-')
		i++;
	if (args[1][i] == '\0')
	{
		ft_puterr3(PRE_OUT, "exit: ", args[1], ": numeric argument required\n");
		minishell_exit(2);
	}
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
		{
			ft_puterr3(PRE_OUT, "exit: ", args[1], ": numeric argument required\n");
			minishell_exit(2);
		}
		i++;
	}
	if (args[2])
		return (ft_puterr1(PRE_OUT, "exit: too many arguments\n"), 1);
	_check_overflow(args[1]);
	minishell_exit(ft_atoi(args[1]));
	return (0);
}
