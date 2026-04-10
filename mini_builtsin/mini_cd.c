/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:04:28 by cn-goie           #+#    #+#             */
/*   Updated: 2026/04/10 15:13:53 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_exec.h"
#include "minishell.h"

int builtin_cd(char **args, t_env **env_list)
{
    (void)env_list;
    if (!args[1])
    {
        ft_putendl_fd("minishell: cd: home not set (simple version)", 2);
        return (1);
    }
    if (chdir(args[1]) != 0)
    {
        perror("minishell: cd");
        return (1);
    }
    return (0);
}