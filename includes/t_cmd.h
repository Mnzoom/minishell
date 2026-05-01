/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:58:15 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/01 22:06:47 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CMD_H
# define T_CMD_H

# include <stddef.h>
# include "t_token.h"
# include "t_redirect.h"

typedef struct s_cmd
{
	char			**m_args;
	t_redirect		*m_redirect_list;
	struct s_cmd	*next;
}	t_cmd;

t_cmd		*t_cmd__m_new(size_t arg_count);
t_token		*t_cmd__add_m_redirect(t_cmd *m_cmd, t_token *m_token);
void		t_cmd__free(t_cmd *m_cmd);
void		t_cmd__freeall(t_cmd *m_cmd_list);
void		t_cmd__print(t_cmd *cmd);

#endif