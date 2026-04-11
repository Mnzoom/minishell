/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:59:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/11 14:37:59 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	_dbg_print_tokens(t_token *m_token_list)
{
	t_token	*node;

	node = m_token_list;
	while (node != NULL)
	{
		t_token__print(node);
		node = node->next;
	}
}

void	_dbg_print_cmd(t_cmd *m_cmd_list)
{
	t_cmd *node;

	node = m_cmd_list;
	while (node != NULL)
	{
		t_cmd__print(node);
		node = node->next;
	}
}

t_cmd	*mini_parse(char *line, t_env *m_env_list)
{
	t_token	*m_token_list;
	t_cmd	*m_cmd_list;

	m_token_list = tokenize(line);
	if (!token_verifier(m_token_list))
		return (NULL);
	token_refinery(m_token_list, m_env_list);
	_dbg_print_tokens(m_token_list);
	m_cmd_list = cmd_shipper(m_token_list);
	t_token__m_free_all(m_token_list, FALSE);
	return (m_cmd_list);
}
