/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_bridge.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:17:09 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/10 14:33:11 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BRIDGE_H
# define MINI_BRIDGE_H

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

t_cmd	*mini_parse(char *line, char **envp);
void	mini_exec(t_cmd *cmd_linked_list);

#endif