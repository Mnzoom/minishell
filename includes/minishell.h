/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:15:56 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 21:19:17 by thantoni         ###   ########.fr       */
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

# define PRE_IN "bash-0.0$ "
# define PRE_OUT "bash: "

void	setup_inputs_signals(void);
int		handle_input_line_exit(char *line);

t_env	*main_cache_envp(char **envp);

#endif