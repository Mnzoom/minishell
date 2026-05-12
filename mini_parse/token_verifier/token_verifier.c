/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_verifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:22:25 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 11:21:45 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"
#include "libft.h"

int	_are_quotes_closed(t_token *m_token)
{
	size_t	i;
	int		in_single;
	int		in_double;

	if (!m_token || !m_token->raw)
		return (TRUE);
	i = 0;
	in_single = 0;
	in_double = 0;
	while (i < m_token->raw_len && m_token->raw[i] != '\0')
	{
		if (m_token->raw[i] == '\'' && in_double == 0)
			in_single = !in_single;
		else if (m_token->raw[i] == '\"' && in_single == 0)
			in_double = !in_double;
		i++;
	}
	if (in_single == 1 || in_double == 1)
		return (FALSE);
	return (TRUE);
}

int	token_verifier(t_token *m_token_list)
{
	t_token	*m_token;

	if (!m_token_list)
		return (TRUE);
	m_token = m_token_list;
	if (m_token->type == PIPE)
		return (ft_puterr1(PRE_OUT, ERR_SYNTAX_PIPE), FALSE);
	while (m_token != NULL)
	{
		if (t_token_type__is_redirection(m_token->type))
		{
			if (m_token->next == NULL)
				return (ft_puterr1(PRE_OUT, ERR_SYNTAX_NL), FALSE);
			if (m_token->next->type != STR)
				return (ft_puterr1(PRE_OUT, ERR_SYNTAX_GENERIC), FALSE);
		}
		if (m_token->type == PIPE
			&& (m_token->next == NULL || m_token->next->type == PIPE))
			return (ft_puterr1(PRE_OUT, ERR_SYNTAX_PIPE), FALSE);
		if (!_are_quotes_closed(m_token))
			return (ft_puterr1(PRE_OUT, ERR_UNCLOSED_QUOTES), FALSE);
		m_token = m_token->next;
	}
	return (TRUE);
}
