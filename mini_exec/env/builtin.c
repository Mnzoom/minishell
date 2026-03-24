/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:54:41 by clementngoi       #+#    #+#             */
/*   Updated: 2026/03/23 14:43:45 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

int is_builtin(char *cmd)
{
    if(!cmd)
        return (0);
    if (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "cd") == 0
    || ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "export") == 0
    || ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "env") == 0
    || ft_strcmp(cmd, "exit") == 0)
    {
        return (0);
    }
    return(1);
}

int exec_builtin(t_cmd *cmd, t_env **env_list)
{
    char *name;

    name = cmd->m_args[0];
    if (ft_strcmp(name, "echo") == 0)
        return (builtin_echo(cmd->m_args));
    if (ft_strcmp(name, "cd") == 0)
        return (builtin_cd(cmd->m_args, env_list));
    if (ft_strcmp(name, "pwd") == 0)
        return (builtin_pwd());
    if (ft_strcmp(name, "export") == 0)
        return (builtin_export(cmd->m_args, env_list));
    if (ft_strcmp(name, "unset") == 0)
        return (builtin_unset(cmd->m_args, env_list));
    if (ft_strcmp(name, "env") == 0)
        return (builtin_env(*env_list));
    if (ft_strcmp(name, "exit") == 0)
        return (builtin_exit(cmd->m_args));
    return (EXIT_FAILURE);
}