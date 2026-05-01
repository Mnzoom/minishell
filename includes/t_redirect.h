/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redirect.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:52:29 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/01 22:00:59 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_REDIRECT_H
# define T_REDIRECT_H

# include "t_token_type.h"

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

t_redirect	*t_redirect__m_new(char *m_name, t_token_type type);
void		t_redirect__free(t_redirect *m_redirect);
void		t_redirect__freeall(t_redirect *m_redirect_list);

#endif