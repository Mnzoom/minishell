/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:23:12 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/01 17:07:42 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

static int	_get_redirection_fd(t_redirect *redir_list)
{
	int	fd;

	fd = -1;
	if (redir_list->type == INFILE)
		fd = open(redir_list->m_value, O_RDONLY);
	else if (redir_list->type == OVERRIDE)
		fd = open(redir_list->m_value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir_list->type == APPEND)
		fd = open(redir_list->m_value, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (redir_list->type == HEREDOC)
		fd = read_heredoc(redir_list->m_value);
	return (fd);
}

int	apply_redirections(t_redirect *redir_list)
{
	t_redirect	*m_node;
	int			fd;

	m_node = redir_list;
	while (m_node)
	{
		fd = _get_redirection_fd(m_node);
		if (fd == -1)
			return (ft_puterr(PRE_OUT), perror(m_node->m_value), -1);
		if (m_node->type == INFILE || m_node->type == HEREDOC)
		{
			if (dup2(fd, STDIN_FILENO) == -1)
				return (perror("dup2 stdin"), close(fd), -1);
		}
		else if (dup2(fd, STDOUT_FILENO) == -1)
			return (perror("dup2 stdout"), close(fd), -1);
		close(fd);
		m_node = m_node->next;
	}
	return (0);
}
