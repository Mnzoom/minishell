/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:48:28 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/10 14:44:54 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

void    exec_child_process(t_cmd *cmd, t_env *env_list)
{
    char    *path;
    char    **envp;
    
    if (is_builtin(cmd->m_args[0]))
    {
        exec_builtin(cmd, &env_list);
        exit(0);
    }
    envp = env_to_tab(env_list);
    path = get_path(cmd->m_args[0], env_list);
    if (!path)
    {
        ft_putstr_fd("minishell: command not found: ", 2);
        ft_putendl_fd(cmd->m_args[0], 2);
        exit(127);
    }
    if (execve(path, cmd->m_args, envp) == -1)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}