/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:59:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/09 16:23:29 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

t_cmd	*mini_parse(char *line, char **envp)
{
	t_token	*m_token_list;
	t_token	*m_token;
	
	m_token_list = tokenize(line);
	if (!token_verifier(m_token_list))
		return (NULL);
	token_expander(m_token_list, envp);
	printf("------- TOKENS -------\n");
	m_token = m_token_list;
	while (m_token != NULL)
	{
		t_token__print(m_token);
		m_token = m_token->next;
	}

	t_token__m_free_all(m_token_list);
	printf("\n\n");
	return (NULL);
}
