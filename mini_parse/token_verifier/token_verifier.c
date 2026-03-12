/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_verifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:22:25 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/12 13:00:18 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"
#include "libft.h"

int	_verify_closed_quotes(t_token *token)
{
	size_t	i;
	int		in_single;
	int		in_double;

	if (!token || !token->raw)
		return (TRUE);
	i = 0;
	in_single = 0;
	in_double = 0;
	while (i < token->raw_len && token->raw[i] != '\0')
	{
		if (token->raw[i] == '\'' && in_double == 0)
			in_single = !in_single;
		else if (token->raw[i] == '\"' && in_single == 0)
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
		return (ft_putstr_fd(ERR_SYNTAX_PIPE, FD_ERR), FALSE);
	while (m_token != NULL)
	{
		if (t_token_type__is_redirection(m_token->type))
		{
			if (m_token->next == NULL)
				return (ft_putstr_fd(ERR_SYNTAX_NL, FD_ERR), FALSE);
			if (m_token->next->type != STR)
				return (ft_putstr_fd(ERR_SYNTAX_GENERIC, FD_ERR), FALSE);
		}
		if (m_token->type == PIPE && (m_token->next == NULL || m_token->next->type == PIPE))
			return (ft_putstr_fd(ERR_SYNTAX_PIPE, FD_ERR), FALSE);
		if (!_verify_closed_quotes(m_token))
			return (ft_putstr_fd(ERR_UNCLOSED_QUOTES, FD_ERR), FALSE);
		m_token = m_token->next;
	}
	return (TRUE);
}
