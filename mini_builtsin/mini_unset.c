/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:07:16 by cn-goie           #+#    #+#             */
/*   Updated: 2026/04/30 17:34:27 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_exec.h"

int mini_unset(char **args, t_env **env_list)
{
	int i;

	if (!args[1])
		return (0);
	i = 1;
	while (args[i])
	{
		t_env__remove_by_key(env_list, args[i]);
		i++;
	}
	return (0);
}