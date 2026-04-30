/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_bridge.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:17:09 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 18:55:12 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BRIDGE_H
# define MINI_BRIDGE_H

# include "minishell.h"
# include <stddef.h>
# include <stdlib.h>

# define EXIT_SUCCESS 0
# define EXIT_ERROR 1
# define TRUE 1
# define FALSE 0

/* PIPE = '|' */
/* OVERRIDE = '>' */
/* APPEND = '>>' */
/* INFILE = '<' */
/* HEREDOC = '<<' */
/* STR = anything that's not ' ', '\t' */
typedef enum e_token_type
{
	PIPE = 0,
	OVERRIDE = 1,
	APPEND = 2,
	INFILE = 3,
	HEREDOC = 4,
	STR = 5
}	t_token_type;

/* char *m_name; Can be in/out filename OR heredoc limiter */
/* t_token_type type;*/
/* int heredoc_fd;*/
/* struct s_redirect *next;*/
typedef struct s_redirect
{
	char					*m_value;
	t_token_type			type;
	int						heredoc_fd;
	struct s_redirect		*next;
}	t_redirect;

typedef struct s_cmd
{
	char			**m_args;
	t_redirect		*m_redirect_list;
	struct s_cmd	*next;
}	t_cmd;

t_cmd	*mini_parse(char *line, t_env *m_env_list);
int    exec_pipe(t_cmd *cmd_list, t_env *env_list);
int    mini_exec(t_cmd *cmd_list, t_env **env_list);
void free_cmd_list(t_cmd *lst);
void	free_redirect_list(t_redirect *redir);
void	free_tab(char **tab);

#endif