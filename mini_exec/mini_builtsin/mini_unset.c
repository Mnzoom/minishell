/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:07:16 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/10 03:20:27 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_exec.h"

int mini_unset(char **args, t_env **env_list)
{
	int i;
	int status;

	if (!args[1])
		return (0);
	i = 1;
	status = 0;
	while (args[i])
	{
		if (!env_is_key_valid(args[i]))
		{
			ft_puterr3(PRE_OUT, "unset: `", args[i], "': not a valid identifier\n");
			status = 1;
		}
		else
			t_env__remove_by_key(env_list, args[i]);
		i++;
	}
	return (status);
}