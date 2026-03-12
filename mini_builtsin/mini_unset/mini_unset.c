/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:01:30 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/12 12:58:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils/env_parsing.h"
#include "libft.h"

int	mini_unset(char **args, t_env **m_env_list)
{
	size_t	i;
	int		status;

	i = 1;
	status = 0;
	while (args[i] != NULL)
	{
		if (!env_is_key_valid(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", FD_ERR);
			ft_putstr_fd(args[i], FD_ERR);
			ft_putstr_fd("': not a valid identifier\n", FD_ERR);
			status = 1;
		}
		else
			t_env__remove_by_key(m_env_list, args[i]);
		i++;
	}
	return (status);
}
