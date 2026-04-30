/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:55:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/30 19:02:04 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

extern int g_lastsignal;

int	exec_pipe(t_cmd *cmd_list, t_env *env_list)
{
	int		pipe_fd[2];
	int		fd_in;
	pid_t	last_pid;
	int		status;

	fd_in = STDERR_FILENO;
	while (cmd_list)
	{
		if (pipe(pipe_fd) == -1)
			perror("pipe");
		last_pid = fork();
		if (last_pid == -1)
			perror("fork");
		if (last_pid == 0)
		{
			dup2(fd_in, STDIN_FILENO);
			if (fd_in != STDERR_FILENO)
				close(fd_in);
			if (cmd_list->next)
				dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			exec_child_process(cmd_list, env_list);
			exit(1); 
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
	close(fd_in);
	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		g_lastsignal = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_lastsignal = 128 + WTERMSIG(status);
	while (wait(NULL) > 0)
		;
	return (g_lastsignal);
}
