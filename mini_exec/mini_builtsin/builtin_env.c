/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:05:43 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/05 19:43:56 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_exec.h"

int builtin_env(t_env *env_list)
{
	while (env_list)
	{
		if (env_list->m_val)
		{
			ft_putstr_fd(env_list->m_key, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(env_list->m_val, 1);
		}
		env_list = env_list->next;
	}
	return (0);
}
