/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:14:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/10 16:12:11 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "libft.h" 

int g_last_signal = 0;

int main(int argc, char **argv, char **envp)
{
    t_env   *m_env_list;
    char    *line;
    t_cmd   *cmd_list; 

    (void)argc, (void)argv;
    m_env_list = main_cache_envp(envp);
    setup_inputs_signals();
    while (TRUE)
    {
        line = readline("minishell> ");
        if (handle_input_line_exit(line))
            break ;
        if (line && *line) 
        {
            add_history(line);
            cmd_list = mini_parse(line, m_env_list);
            if (cmd_list)
			{
    			mini_exec(cmd_list, &m_env_list);
    			t_list__clear_nodes((t_list **)&cmd_list); // Correction ici
			}
        }
        free(line);
    }
    t_env__free_all(m_env_list);
    return (EXIT_SUCCESS);
}