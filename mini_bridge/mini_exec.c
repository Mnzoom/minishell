/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:05:45 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/10 16:16:06 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "mini_exec.h"

int    mini_exec(t_cmd *cmd_list, t_env **env_list)
{
    int status;

    status = 0;
    if (!cmd_list || !cmd_list->m_args || !cmd_list->m_args[0])
        return (0);

   
    if (cmd_list && !cmd_list->next && is_builtin(cmd_list->m_args[0]))
    {
        int save_stdout = dup(STDOUT_FILENO);
        int save_stdin = dup(STDIN_FILENO);

        apply_redirections(cmd_list->m_redirect_list);
        
        
        status = exec_builtin(cmd_list, env_list);

        dup2(save_stdout, STDOUT_FILENO);
        dup2(save_stdin, STDIN_FILENO);
        close(save_stdout);
        close(save_stdin);
    }

    else
    {
    
        status = execute_pipe(cmd_list, *env_list);
    }
    return (status);
}