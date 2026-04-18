/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_bridge.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:17:09 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/18 13:41:10 by cn-goie          ###   ########.fr       */
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

typedef enum e_token_type
{
	PIPE = 0, // |
	OVERRIDE = 1, // >
	APPEND = 2, // >>
	INFILE = 3, // <
	HEREDOC = 4, // <<
	STR = 5 // anything that's not ' ', '\t' 
}	t_token_type;

//forced to malloc, need to store name + type
typedef struct s_redirect
{
	/** Can be in/out filename OR heredoc limiter */
	char					*m_value;
	t_token_type			type;
	struct s_redirect		*next;
}	t_redirect;

typedef struct s_cmd
{
	char			**m_args;
	t_redirect		*m_redirect_list;
	struct s_cmd	*next;
}	t_cmd;

t_cmd	*mini_parse(char *line, t_env *m_env_list);
int    execute_pipe(t_cmd *cmd_list, t_env *env_list);
int    mini_exec(t_cmd *cmd_list, t_env **env_list);
void free_cmd_list(t_cmd *lst);
void	free_redirect_list(t_redirect *redir);
void	free_tab(char **tab);

#endif