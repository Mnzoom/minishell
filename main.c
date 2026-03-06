/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:14:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 14:50:59 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_last_signal = 0;

int	main(int argc, char **argv, char **envp)
{
	char *line;

	(void)argc;
	(void)argv;
	(void)envp;
	setup_inputs_signals();
	while (TRUE)
	{
		line = readline("minishell> ");
		if (handle_input_line_exit(line))
			break;
		add_history(line);
		mini_exec(mini_parse(line));
		free(line);
	}
	return (EXIT_SUCCESS);
}