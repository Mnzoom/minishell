/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:21:09 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/10 15:55:19 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

/*void    exec_cmds(t_cmd *cmd_list, t_env **env_list)
{
    int save_stdout;
    int save_stdin;
    
    if (cmd_list && cmd_list->m_args && cmd_list->m_args[0] 
    && !cmd_list->next && is_builtin(cmd_list->m_args[0]))
    {
        save_stdout = dup(STDOUT_FILENO);
        save_stdin = dup(STDIN_FILENO);
        apply_redirections(cmd_list->m_redirect_list);
        exec_builtin(cmd_list, env_list);
        dup2(save_stdout, STDOUT_FILENO);
        dup2(save_stdin, STDIN_FILENO);
        close(save_stdout);
        close(save_stdin);
    }
    else
    {
        execute_pipe(cmd_list, *env_list);
    }
}*/

void    exec_cmds(t_cmd *cmd_list, t_env **env_list)
{
    printf("ENTREE DANS EXEC_CMDS\n");
    if (!cmd_list) return ;
    
    if (cmd_list->m_args && cmd_list->m_args[0])
    {
        printf("COMMANDE DETECTEE : %s\n", cmd_list->m_args[0]);
        if (is_builtin(cmd_list->m_args[0]))
        {
            printf("C'EST UN BUILTIN\n");
            exec_builtin(cmd_list, env_list);
        }
        else
            printf("C'EST UNE COMMANDE EXTERNE\n");
    }
}