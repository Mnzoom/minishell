/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_verifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:22:25 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 17:56:42 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"
#include "libft.h"

int	token_verifier(t_token *tokens)
{
	t_token *current;
	
	if (!tokens)
		return (TRUE);
	current = tokens;
	if (current->type == PIPE)
		return (ft_putstr_fd(ERR_SYNTAX_PIPE, FD_ERR), FALSE);
	while (current != NULL)
	{
		if (t_token_type__is_redirection(current->type))
		{
			if (current->next == NULL)
				return (ft_putstr_fd(ERR_SYNTAX_NL, FD_ERR), FALSE);
			if (current->next->type != STR)
				return (ft_putstr_fd(ERR_SYNTAX_GENERIC, FD_ERR), FALSE);
		}
		if (current->type == PIPE && (current->next == NULL || current->next->type == PIPE))
			return (ft_putstr_fd(ERR_SYNTAX_PIPE, FD_ERR), FALSE);
		current = current->next;
	}
	return (TRUE);
}
