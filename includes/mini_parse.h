/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:16:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 09:31:13 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSE_H
# define MINI_PARSE_H

# include <stdio.h>
# include "minishell.h"
# include "mini_bridge.h"
# include "libft.h"

# define ERR_SYNTAX_PIPE "syntax error near unexpected token `|'\n"
# define ERR_SYNTAX_NL "syntax error near unexpected token `newline'\n"
# define ERR_SYNTAX_GENERIC "syntax error near unexpected token\n"
# define ERR_UNCLOSED_QUOTES "syntax error unclosed quotes\n"

size_t		get_var_name_len(char *var_name);
size_t		get_lastsig_len(void);

typedef struct s_parse_info
{
	size_t	raw_i;
	size_t	exp_i;
	int		in_single;
	int		in_double;
	int		has_quotes;
	int		rm_quotes;
	int		is_exp;
}	t_parse_info;

//--- tokenizer
t_token		*tokenize(char *line);

//--- token_verifier
int			token_verifier(t_token *m_token_list);
void		compute_modifs_len(t_token *m_token, t_env *m_env_list, int exp, int rm_quotes);
int			ft_isenvpattern(char *str);
int			ft_issigpattern(char *str);
int			ft_isenvchar(char c);
void		handle_modifs(t_token *m_token, t_env *m_env_list, int exp, int rm_quotes);
void		modif_expand_env(t_token *m_token, t_env *m_env_list, t_parse_info *info);
void		modif_expand_sig(t_token *m_token, t_parse_info *info);
size_t		modif_handle_quote_skip(char *raw, int *in_single, int *in_double);

//--- token_refinery
void		token_refinery(t_token *m_token_list, t_env *m_env_list);

//--- token_splitter
void		token_splitter(t_token **m_token_list);

//--- cmd_shipper
t_cmd		*cmd_shipper(t_token *m_token_list);

#endif