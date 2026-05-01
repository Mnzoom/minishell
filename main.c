/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:14:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/01 21:56:42 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "libft.h" 

int	g_lastsignal = 0;

int main(int argc, char **argv, char **envp)
{
	t_env	*m_env_list;
	char	*line;
	t_cmd	*m_cmd_list;

	(void)argc, (void)argv;
	m_env_list = main_cache_envp(envp);
	setup_inputs_signals();
	while (TRUE)
	{
		line = readline(PRE_IN);
		if (handle_input_line_exit(line))
			break ;
		if (!line)
			return (t_env__free_all(m_env_list), EXIT_FAILURE);
		if (*line)
		{
			add_history(line);
			m_cmd_list = mini_parse(line, m_env_list);
			if (m_cmd_list)
			{
				g_lastsignal = mini_exec(m_cmd_list, &m_env_list);
				t_cmd__freeall(m_cmd_list);
				m_cmd_list = NULL;
			}
		}
		free(line);
	}
	return (t_env__free_all(m_env_list), EXIT_SUCCESS);
}
