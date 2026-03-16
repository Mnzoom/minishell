/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:14:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:37:34 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	g_last_signal = 0;

int	main(int argc, char **argv, char **envp)
{
	t_env	*m_env_list;
	char	*line;

	(void)argc, (void)argv, (void)envp;
	m_env_list = main_cache_envp(envp);
	// t_env__print_all(m_env_list);
	setup_inputs_signals();
	while (TRUE)
	{
		line = readline("minishell> ");
		if (handle_input_line_exit(line))
			break ;
		add_history(line);
		mini_exec(mini_parse(line, envp));
		free(line);
	}
	t_env__free_all(m_env_list);
	return (EXIT_SUCCESS);
}
