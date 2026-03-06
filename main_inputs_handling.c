/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_inputs_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:31:42 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 13:29:20 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define _POSIX_C_SOURCE 200809L
#include "minishell.h"

extern int g_last_signal;

static void _f_handler_sigint_behaviour(int signal)
{
	g_last_signal = signal;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	_set_sigaction(int signal, void (*f)(int))
{
	struct sigaction sa;

	sa.sa_handler = f;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(signal, &sa, NULL);
}

void setup_inputs_signals(void)
{
	_set_sigaction(SIGINT, _f_handler_sigint_behaviour);
	_set_sigaction(SIGQUIT, (void *)SIG_IGN);
}

int	handle_input_line_exit(char *line)
{
	if (line == NULL)
		return (printf("exit\n"), TRUE);
	return (FALSE);
}