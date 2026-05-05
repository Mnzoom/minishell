/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:59:29 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/04 14:05:19 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

# include <stddef.h>
# include "t_token_type.h"

typedef struct s_token
{
	char			*raw;
	size_t			raw_len;
	char			*m_value;
	int				modifs_len;
	int				is_ignored;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

t_token		*t_token__m_new(char *start, size_t len, t_token_type type);
void		t_token__m_free(t_token *m_token);
void		t_token__m_free_all(t_token *m_token_list);
void		t_token__print(t_token *token);
t_token		*t_token__parse_value_str(char *start);

#endif