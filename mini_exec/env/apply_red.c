/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:23:12 by clementngoi       #+#    #+#             */
/*   Updated: 2026/03/23 14:45:54 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"

void    apply_redirections(t_redirect *redir_list)
{
    int fd;
    while (redir_list)
    {
        if (redir_list->type == INFILE)
        {
            fd = open(redir_list->m_value, O_RDONLY);
            if (fd == -1) { perror("minishell"); exit(1);}
            dup2(fd, STDIN_FILENO);
            close(fd);
        }
        else if (redir_list->type == HEREDOC)
        {
            fd = read_heredoc(redir_list->m_value);
            if (fd != -1)
            {
                dup2(fd, STDIN_FILENO);
                close(fd);
            }
        }
        else if (redir_list->type == OVERRIDE)
        {
            fd = open(redir_list->m_value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) { perror("minishell"); exit(1); }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
        else if (redir_list->type == APPEND)
        {
            fd = open(redir_list->m_value, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd == -1) { perror("minishell"); exit(1); }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
        redir_list = redir_list->next;
    }
}
