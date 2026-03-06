/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:14:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 13:27:06 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_last_signal = 0;

int	main(int argc, char **argv)
{
	char *line;

	setup_inputs_signals();
	while (TRUE)
	{
		line = readline("minishell> ");
		if (handle_input_line_exit(line))
			break;
		add_history(line);
		mini_exec(mini_parse(argc, argv));
		free(line);
	}
	return (EXIT_SUCCESS);
}