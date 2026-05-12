/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:05:58 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/12 05:44:25 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_exec.h"
#include <limits.h>

extern int	g_lastsignal;

static void	_verify_limits(char *str, int sign, \
	unsigned long long result, int i)
{
	unsigned long long	limit;
	unsigned long long	max_div_10;

	max_div_10 = (unsigned long long)LLONG_MAX / 10;
	limit = (unsigned long long)LLONG_MAX % 10;
	if (sign == -1)
		limit += 1;
	if (result > max_div_10
		|| (result == max_div_10 && (unsigned long long)(str[i] - '0') > limit))
	{
		ft_puterr3(PRE_OUT, "exit: ", str, ": numeric argument required\n");
		minishell_exit(2);
	}
}

static void	_check_overflow(char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i])
	{
		_verify_limits(str, sign, result, i);
		result = result * 10 + (str[i] - '0');
		i++;
	}
}

static void	_validate_str_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
	{
		ft_puterr3(PRE_OUT, "exit: ", str, ": numeric argument required\n");
		minishell_exit(2);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_puterr3(PRE_OUT, "exit: ", str, ": numeric argument required\n");
			minishell_exit(2);
		}
		i++;
	}
}

int	mini_exit(char **args)
{
	ft_putendl_fd("exit", 1);
	if (!args[1])
		minishell_exit(g_lastsignal);
	_validate_str_number(args[1]);
	if (args[2])
		return (ft_puterr1(PRE_OUT, "exit: too many arguments\n"), 1);
	_check_overflow(args[1]);
	minishell_exit(ft_atoi(args[1]));
	return (0);
}
