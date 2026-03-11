/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:59:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/10 15:33:01 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

t_cmd	*mini_parse(char *line, char **envp)
{
	t_token	*m_token_list;
	t_token	*m_token;
	t_cmd	*m_cmd_list;
	t_cmd	*m_cmd;
	
	m_token_list = tokenize(line);
	if (!token_verifier(m_token_list))
		return (NULL);
	token_refinery(m_token_list, envp);
	m_token = m_token_list;
	while (m_token != NULL)
	{
		t_token__print(m_token);
		m_token = m_token->next;
	}
	m_cmd_list = cmd_shipper(m_token_list);
	t_token__m_free_all(m_token_list, FALSE);
	m_cmd = m_cmd_list;
	while (m_cmd != NULL)
	{
		t_cmd__print(m_cmd);
		m_cmd = m_cmd->next;
	}
	printf("\n\n");
	return (m_cmd_list);
}
