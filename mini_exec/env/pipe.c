/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:55:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/13 11:03:11 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

int    execute_pipe(t_cmd *cmd_list, t_env *env_list)
{
    int     pipe_fd[2];
    int     fd_in = 0;
    pid_t   pid;
    int     status;
    int     last_status = 0;

    while (cmd_list)
    {
        if (pipe(pipe_fd) == -1)
            perror("pipe");
        pid = fork();
        if (pid == -1)
            perror("fork");
        if (pid == 0)
        {
            /*enfant*/
            dup2(fd_in, STDIN_FILENO);
            if (fd_in != 0)
                close(fd_in);
            if (cmd_list->next)
                dup2(pipe_fd[1], STDOUT_FILENO);
            close(pipe_fd[0]);
            close(pipe_fd[1]);
            apply_redirections(cmd_list->m_redirect_list);
            exec_child_process(cmd_list, env_list);
            exit(1); /* Sécurité si exec_child_process fail */
        }
        else
        {
            /*parent*/
            if (fd_in != 0)
                close(fd_in);
            close(pipe_fd[1]);
            fd_in = pipe_fd[0];
            cmd_list = cmd_list->next;
        }
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        last_status = WEXITSTATUS(status);
    while (wait(NULL) > 0);
    
    return (last_status);
}