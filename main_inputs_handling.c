/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_inputs_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:31:42 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 14:37:26 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "minishell.h"
#define _POSIX_C_SOURCE 200809L

extern int	g_lastsignal;

static void	_f_handler_sigint_behaviour(int signal)
{
	g_lastsignal = 128 + signal;
	write(1, "^C\n", 3);
	rl_replace_line("", 0);
	rl_on_new_line();
	if (RL_ISSTATE(RL_STATE_READCMD))
		rl_redisplay();
}

void	set_sigaction(int signal, void (*f)(int))
{
	struct sigaction	sa;

	sa.sa_handler = f;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(signal, &sa, NULL);
}

void	setup_inputs_signals(void)
{
	rl_catch_signals = 0;
	set_sigaction(SIGINT, _f_handler_sigint_behaviour);
	set_sigaction(SIGQUIT, (void *)SIG_IGN);
}

int	handle_input_line_exit(char *line)
{
	if (line == NULL)
		return (printf("exit\n"), TRUE);
	return (FALSE);
}
