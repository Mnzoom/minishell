/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:01:30 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/11 17:18:53 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	_is_key_valid(char *key)
{
	int	i;

	if (!key || !key[0] || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (FALSE);
	i = 1;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	mini_unset(char **args, t_env **m_env_list)
{
	size_t	i;
	int		status;

	i = 1;
	status = 0;
	while (args[i] != NULL)
	{
		if (!_is_key_valid(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			status = 1;
		}
		else
			t_env__remove_by_key(m_env_list, args[i]);
		i++;
	}
	return (status);
}
