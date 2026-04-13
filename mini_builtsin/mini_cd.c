/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:04:28 by cn-goie           #+#    #+#             */
/*   Updated: 2026/04/13 16:48:45 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include <unistd.h>
#include <stdio.h> 

char    *t_env__get_val(t_env *m_env_list, char *key)
{
    t_env   *curr;
    size_t  target_len;

    if (!m_env_list || !key)
        return (NULL);
    target_len = ft_strlen(key);
    curr = m_env_list;
    while (curr)
    {
        if (curr->key_len == target_len && 
            ft_strncmp(curr->m_key, key, target_len) == 0)
            return (curr->m_val);
        curr = curr->next;
    }
    return (NULL);
}

void    t_env_update_var(t_env **m_env_list, char *key, char *new_val)
{
    t_env   *curr;
    size_t  k_len;

    if (!m_env_list || !key || !new_val)
        return;
    k_len = ft_strlen(key);
    curr = *m_env_list;
    while (curr)
    {
        if (curr->key_len == k_len && ft_strncmp(curr->m_key, key, k_len) == 0)
        {
            free(curr->m_val);
            curr->m_val = ft_strdup(new_val);
            curr->val_len = ft_strlen(new_val);
            return;
        }
        curr = curr->next;
    }
}

int builtin_cd(char **args, t_env **env_list)
{
    char cwd[4096];
    char *old_pwd_val;

    if (!args[1])
        return (1);
    old_pwd_val = t_env__get_val(*env_list, "PWD");
    if (chdir(args[1]) != 0)
    {
        perror("minishell: cd");
        return (1);
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        if (old_pwd_val)
            t_env_update_var(env_list, "OLDPWD", old_pwd_val);
        t_env_update_var(env_list, "PWD", cwd);
    }
    return (0);
}