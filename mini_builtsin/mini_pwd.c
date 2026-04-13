/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:05:30 by cn-goie           #+#    #+#             */
/*   Updated: 2026/04/13 11:40:50 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>

int builtin_pwd(t_env *env_list)
{
    char *pwd_env;
    char cwd[4096];

   
    pwd_env = t_env_get_val(env_list, "PWD");
    if (pwd_env)
    {
        ft_putendl_fd(pwd_env, 1);
        return (0);
    }

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        ft_putendl_fd(cwd, 1); 
        return (0);
    }
    perror("pwd");
    return (1);
}
