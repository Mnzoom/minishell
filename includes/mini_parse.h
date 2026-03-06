/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:16:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 18:52:29 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSE_H
# define MINI_PARSE_H
//USED ONLY INSIDE EXEC SCOPE
//Anything reached/ reaching outside EXEC MUST be DECLARED inside "mini_bridge.h or minishell.h"

# include "mini_bridge.h"
# include "libft.h"
# include <stdio.h>

# define ERR_SYNTAX_PIPE "minishell: syntax error near unexpected token `|'\n"
# define ERR_SYNTAX_NL "minishell: syntax error near unexpected token `newline'\n"
# define ERR_SYNTAX_GENERIC "minishell: syntax error near unexpected token\n"

typedef enum	e_token_type {
	PIPE = 0, // |
	OVERRIDE = 1, // >
	APPEND = 2, // >>
	INFILE = 3, // <
	HEREDOC = 4, // <<
	STR = 5 // anything that's not ' ', '\t' 
}	t_token_type;

typedef struct	s_token {
	char			*start;
	char			*m_expanded;
	size_t			len;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

//--- tokenizer
t_token	*tokenize(char *line);

//--- token_verifier
int		token_verifier(t_token *tokens);

//--- t_token
t_token	*t_token__m_new(char *start, size_t len, t_token_type type);
void	t_token__m_free(t_token *m_token);
void	t_token__m_free_all(t_token *m_token);
void	t_token__print(t_token *token);
t_token	*t_token__parse_value_str(char *start);

//--- t_token_type
int		t_token_type__is_redirection(t_token_type t);

#endif