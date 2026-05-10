/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:59:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 06:51:41 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

extern int	g_lastsignal;

// static void	_dbg_print_tokens(t_token *m_token_list)
// {
// 	t_token	*node;

// 	node = m_token_list;
// 	while (node != NULL)
// 	{
// 		t_token__print(node);
// 		node = node->next;
// 	}
// }

// static void	_dbg_print_cmd(t_cmd *m_cmd_list)
// {
// 	t_cmd *node;

// 	node = m_cmd_list;
// 	while (node != NULL)
// 	{
// 		t_cmd__print(node);
// 		node = node->next;
// 	}
// }

t_cmd	*mini_parse(char *line, t_env *m_env_list)
{
	t_token	*m_token_list;
	t_cmd	*m_cmd_list;

	m_token_list = tokenize(line);
	if (m_token_list == NULL)
		return (NULL);
	if (!token_verifier(m_token_list))
	{
		g_lastsignal = 2;
		return (t_token__m_free_all(m_token_list), NULL);
	}
	token_refinery(m_token_list, m_env_list);
	token_splitter(&m_token_list);
	m_cmd_list = cmd_shipper(m_token_list);
	t_token__m_free_all(m_token_list);
	return (m_cmd_list);
}
