/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:55:42 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/10 15:15:32 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_exec.h"
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


int builtin_echo(char **args)
{
    int i;
    int n_flag;

    i = 1;
    n_flag = 0;
    
    if (args[i] && ft_strcmp(args[i], "-n") == 0)
    {
        n_flag = 1;
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