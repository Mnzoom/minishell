/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:15:56 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 04:57:03 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "t_env.h"
# include "t_gc.h"
# include "t_line_input.h"

# define PRE_IN "minishell$ "
# define PRE_OUT "minishell: "

void	setup_inputs_signals(void);
void	set_sigaction(int signal, void (*f)(int));
int		handle_input_line_exit(char *line);
void	minishell_exit(int status);

t_env	*main_cache_envp(char **envp);

#endif