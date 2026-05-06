/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:14:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/06 12:36:36 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "libft.h" 

int	g_lastsignal = 0;

int main(int argc, char **argv, char **envp)
{
	t_env	*m_env_list = NULL;
	t_cmd	*m_cmd_list = NULL;
	char	*line = NULL;

	(void)argc, (void)argv;
	m_env_list = main_cache_envp(envp);
	setup_inputs_signals();
	while (TRUE)
	{
		line = readline(PRE_IN);
		if (handle_input_line_exit(line))
		{
			free(line);
			break ;
		}
		if (!line)
			return (minishell_exit(EXIT_SUCCESS), EXIT_FAILURE);
		if (*line)
		{
			add_history(line);
			m_cmd_list = mini_parse(line, m_env_list);
			if (m_cmd_list != NULL)
			{
				g_lastsignal = mini_exec(m_cmd_list, &m_env_list);
				t_cmd__freeall(m_cmd_list);
				m_cmd_list = NULL;
			}
		}
		free(line);
	}
	return (minishell_exit(EXIT_SUCCESS), EXIT_SUCCESS);
}
