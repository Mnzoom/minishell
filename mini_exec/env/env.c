/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:40:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/03/22 19:08:11 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

static int  count_env(t_env *env)
{
    int i;
    i = 0;
    while(env)
    {
        i++;
        env = env->next;
    }
    return(i);
}

char    **env_to_tab(t_env *env_list)
{
    char    **envp;
    char    *tmp;
    int     i;

    envp = malloc(sizeof(char *) * (count_env(env_list) + 1));
    if(!envp)
        return (EXIT_FAILURE);
    i = 0;
    while(env_list)
    {
        tmp = ft_strjoin(env_list->m_key, "=");
        envp[i] = ft_strjoin(tmp, env_list->m_val);
        free(tmp);
        env_list = env_list->next;
        i++;
    }
    envp[i] = NULL;
    return (envp);
}
