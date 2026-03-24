/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:55:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/03/23 13:32:00 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

void    execute_pipe(t_cmd *cmd_list, t_env *env_list)
{
    int     pipe_fd[2];
    int     fd_in = 0;
    pid_t   pid;

    while (cmd_list)
    {
        if (pipe(pipe_fd) == -1)
            perror("pipe");
        pid = fork();
        if (pid == 0)
        {
            dup2(fd_in, STDIN_FILENO);
            if (fd_in != 0)
                close(fd_in);
            if (cmd_list->next)
                dup2(pipe_fd[1], STDOUT_FILENO);
            
            close(pipe_fd[0]);
            close(pipe_fd[1]);
            apply_redirections(cmd_list->m_redirect_list);
            exec_child_process(cmd_list, env_list);
        }
        else
        {
            if (fd_in != 0)
                close(fd_in);
            close(pipe_fd[1]);
            fd_in = pipe_fd[0];
            cmd_list = cmd_list->next;
        }
    }
    while (wait(NULL) > 0);
}