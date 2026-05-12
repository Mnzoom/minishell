/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:55:34 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/12 04:06:02 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

extern int	g_lastsignal;

static void	_handle_pipe_child(t_cmd *m_cmd, t_env *m_env, int *pipe_fd, \
	int fd_in)
{
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	if (m_cmd->next)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	exec_child_process(m_cmd, m_env);
	minishell_exit(1);
}

static void	_handle_pipe_parent(t_cmd **m_cmd, int *pipe_fd, int *fd_in)
{
	close(*fd_in);
	if ((*m_cmd)->next)
	{
		close(pipe_fd[1]);
		*fd_in = pipe_fd[0];
	}
	*m_cmd = (*m_cmd)->next;
}

static void	_wait_children(pid_t last_pid)
{
	int	status;

	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		g_lastsignal = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_lastsignal = 128 + WTERMSIG(status);
	while (wait(NULL) > 0)
		continue ;
}

int	exec_pipe(t_cmd *m_cmd_list, t_env *m_env_list)
{
	int		pipe_fd[2];
	int		fd_in;
	pid_t	last_pid;

	fd_in = dup(STDIN_FILENO);
	while (m_cmd_list)
	{
		if (m_cmd_list->next)
		{
			if (pipe(pipe_fd) == -1)
				perror("pipe");
		}
		last_pid = fork();
		if (last_pid == -1)
			perror("fork");
		if (last_pid == 0)
			_handle_pipe_child(m_cmd_list, m_env_list, pipe_fd, fd_in);
		else
			_handle_pipe_parent(&m_cmd_list, pipe_fd, &fd_in);
	}
	_wait_children(last_pid);
	return (g_lastsignal);
}
