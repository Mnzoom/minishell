/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_verifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:22:25 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/09 16:00:09 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"
#include "libft.h"

int _verify_closed_quotes(t_token *token)
{
    size_t  i;
    int     in_single;
    int     in_double;

    if (!token || !token->raw)
        return (TRUE); // Sécurité de base

    i = 0;
    in_single = 0;
    in_double = 0;
    
    // On parcourt exactement la longueur du token
    while (i < token->raw_len && token->raw[i] != '\0')
    {
        // Si on croise un ' ET qu'on n'est pas enfermé dans des "
        if (token->raw[i] == '\'' && in_double == 0)
            in_single = !in_single; // On bascule l'état (ouvre/ferme)
            
        // Si on croise un " ET qu'on n'est pas enfermé dans des '
        else if (token->raw[i] == '\"' && in_single == 0)
            in_double = !in_double; // On bascule l'état (ouvre/ferme)
            
        i++;
    }

    // À la toute fin, si l'un des deux états est resté ouvert, c'est une erreur !
    if (in_single == 1 || in_double == 1)
        return (FALSE); // FALSE : Les quotes ne sont pas fermées

    return (TRUE); // TRUE : Tout est parfaitement fermé
}

int	token_verifier(t_token *m_token_list)
{
	t_token *m_token;
	
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
