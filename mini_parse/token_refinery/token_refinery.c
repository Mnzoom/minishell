/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_refinery.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:52:38 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/09 06:59:11 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	token_refinery(t_token *m_token_list, t_env *m_env_list)
{
	t_token	*m_token;
	int		exp;

	m_token = m_token_list;
	while (m_token != NULL)
	{
		if (m_token->type == STR)
		{
			exp = 1;
			if (m_token->prev && m_token->prev->type == HEREDOC)
				exp = 0;
			compute_modifs_len(m_token, m_env_list, exp, 1);
			handle_modifs(m_token, m_env_list, exp, 1);
		}
		m_token = m_token->next;
	}
}