/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:23:12 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/10 15:48:31 by cn-goie          ###   ########.fr       */
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
            fd = open(redir_list->m_value, O_RDONLY);
        else if (redir_list->type == OVERRIDE)
            fd = open(redir_list->m_value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        else if (redir_list->type == APPEND)
            fd = open(redir_list->m_value, O_WRONLY | O_CREAT | O_APPEND, 0644);
        else if (redir_list->type == HEREDOC)
            fd = read_heredoc(redir_list->m_value);

        if (fd == -1) 
        {
            perror("minishell");
            return ;
        }
        
        if (redir_list->type == INFILE || redir_list->type == HEREDOC)
            dup2(fd, STDIN_FILENO);
        else
            dup2(fd, STDOUT_FILENO);
        close(fd);
        redir_list = redir_list->next;
    }
}