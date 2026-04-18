/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:21:09 by clementngoi       #+#    #+#             */
/*   Updated: 2026/04/18 13:40:45 by cn-goie          ###   ########.fr       */
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
}

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
}*/

void    exec_cmds(t_cmd *cmd_list, t_env **env_list)
{
    int save_stdout;
    int save_stdin;
    int save_stderr;
    
    if (cmd_list && cmd_list->m_args && cmd_list->m_args[0] 
    && !cmd_list->next && is_builtin(cmd_list->m_args[0]))
    {
        save_stdout = dup(STDOUT_FILENO);
        save_stdin = dup(STDIN_FILENO);
        save_stderr = dup(STDERR_FILENO);
        
        apply_redirections(cmd_list->m_redirect_list);
        g_lastsignal = exec_builtin(cmd_list, env_list); 
       
        dup2(save_stdout, STDOUT_FILENO);
        dup2(save_stdin, STDIN_FILENO);
        dup2(save_stderr, STDERR_FILENO);
        
        close(save_stdout);
        close(save_stdin);
        close(save_stderr);
    }
    else
    {
        g_lastsignal = execute_pipe(cmd_list, *env_list);
    }
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}


void	free_redirect_list(t_redirect *redir)
{
	t_redirect	*tmp;

	while (redir)
	{
		tmp = redir->next;
		if (redir->m_value) 
			free(redir->m_value);
		free(redir);
		redir = tmp;
	}
}

void	free_cmd_list(t_cmd *lst)
{
	t_cmd	*tmp;

	while (lst)
	{
		tmp = lst->next;
		if (lst->m_args)
			free_tab(lst->m_args);
		if (lst->m_redirect_list)
			free_redirect_list(lst->m_redirect_list);
		free(lst);
		lst = tmp;
	}
}