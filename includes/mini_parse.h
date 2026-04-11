/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:16:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/11 17:35:32 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSE_H
# define MINI_PARSE_H
//USED ONLY INSIDE EXEC SCOPE
//Anything reached/ reaching outside EXEC MUST be DECLARED inside "mini_bridge.h or minishell.h"

# include "minishell.h"
# include "mini_bridge.h"
# include "libft.h"
# include <stdio.h>

# define ERR_SYNTAX_PIPE "minishell: syntax error near unexpected token `|'\n"
# define ERR_SYNTAX_NL "minishell: syntax error near unexpected token `newline'\n"
# define ERR_SYNTAX_GENERIC "minishell: syntax error near unexpected token\n"
# define ERR_UNCLOSED_QUOTES "minishell: syntax error unclosed quotes\n"

typedef struct s_token
{
	char			*raw;
	size_t			raw_len;
	char			*m_value;
	int				modifs_len;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

size_t		get_var_name_len(char *var_name);
size_t		get_lastsig_len(void);


//--- tokenizer
t_token		*tokenize(char *line);

//--- token_verifier
int			token_verifier(t_token *m_token_list);
void		compute_modifs_len(t_token *m_token, t_env *m_env_list);
int			ft_isenvpattern(char *str);
int			ft_issigpattern(char *str);
int			ft_isenvchar(char c);
void		handle_modifs(t_token *m_token, t_env *m_env_list);

//--- token_refinery
void		token_refinery(t_token *m_token_list, t_env *m_env_list);

t_cmd		*cmd_shipper(t_token *m_token_list);

//--- t_token
t_token		*t_token__m_new(char *start, size_t len, t_token_type type);
void		t_token__m_free(t_token *m_token, int destroy_value);
void		t_token__m_free_all(t_token *m_token_list, int destroy_value);
void		t_token__print(t_token *token);
t_token		*t_token__parse_value_str(char *start);

//--- t_token_type
int			t_token_type__is_redirection(t_token_type t);
const char	*t_token_type__to_str(t_token_type type);

//--- t_cmd
t_cmd		*t_cmd__m_new(size_t arg_count);
t_token		*t_cmd__add_m_redirect(t_cmd *m_cmd, t_token *m_token);
void		t_cmd__print(t_cmd *cmd);

//--- t_redirect
t_redirect	*t_redirect__m_new(char *m_name, t_token_type type);

#endif