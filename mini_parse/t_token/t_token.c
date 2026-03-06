/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:40:58 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 17:07:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_token__print(t_token *token)
{
	size_t	i;

	i = 0;
	printf("\ntoken:\t");
	while (i < token->len)
	{
		printf("%c", token->start[i]);
		i++;
	}
	printf("\n");
}

t_token	*t_token__m_new(char *start, size_t len, t_token_type type)
{
	t_token *m_token;

	m_token = malloc(sizeof(t_token));
	if (!m_token)
		return (NULL);
	m_token->start = start;
	m_token->len = len;
	m_token->m_expanded = NULL;
	m_token->type = type;
	m_token->next = NULL;
	return (m_token);
}
