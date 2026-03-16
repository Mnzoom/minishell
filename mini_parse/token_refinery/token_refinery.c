/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_refinery.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:52:38 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:44:31 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	token_refinery(t_token *m_token_list, char **envp)
{
	t_token	*token;

	token = m_token_list;
	while (token != NULL)
	{
		if (token->type == STR)
		{
			compute_modifs_len(token, envp);
			handle_modifs(token, envp);
		}
		token = token->next;
	}
}

//TODO: $?swagin --print-> <code>swagin
//TODO: '$USER' --print-> $USER
//Quand " open alors ignore '