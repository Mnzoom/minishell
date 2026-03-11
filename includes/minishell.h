/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:15:56 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/11 17:22:45 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "mini_bridge.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env
{
	char			*m_key;
	char			*m_val;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

void	setup_inputs_signals(void);
int		handle_input_line_exit(char *line);

t_env	*main_cache_envp(char **envp);

//--- t_env
t_env	*t_env__m_new(char *env_var);
void	t_env__free(t_env *env);
void	t_env__free_all(t_env *m_env_list);
void	t_env__print(t_env *m_env);
void	t_env__print_all(t_env *m_env);
t_env	*t_env__get_by_key(t_env *m_env_list, char *key);
t_env	*t_env__extract_by_key(t_env *m_env_list, char *key);
void	t_env__remove_by_key(t_env **m_env_list, char *key);

#endif