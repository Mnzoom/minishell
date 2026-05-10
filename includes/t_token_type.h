/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:00:31 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 09:54:37 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_TYPE_H
# define T_TOKEN_TYPE_H

/* PIPE = '|' */
/* OVERRIDE = '>' */
/* APPEND = '>>' */
/* INFILE = '<' */
/* HEREDOC = '<<' */
/* STR = anything that's not ' ', '\t' */
typedef enum e_token_type
{
	PIPE = '|',
	OVERRIDE = '>',
	APPEND = '>'*'>',
	INFILE = '<',
	HEREDOC = '<'*'<',
	STR = 's'+'t'+'r'
}	t_token_type;

int			t_token_type__is_redirection(t_token_type t);
const char	*t_token_type__to_str(t_token_type type);

#endif