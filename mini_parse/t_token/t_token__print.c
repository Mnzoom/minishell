/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:26:30 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:04:31 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_token__print(t_token *token)
{
	size_t	i;

	i = 0;
	printf("\n__________ TOKEN __________\n");
	printf("\n(%s)token\t\t: ", t_token_type__to_str(token->type));
	while (i < token->raw_len)
	{
		printf("%c", token->raw[i]);
		i++;
	}
	printf("\n");
	if (token->type == STR)
	{
		printf("\nvalue\t\t: %s\n", token->m_value);
		printf("\nmodifs_len\t: %d\n", token->modifs_len);
	}
	printf("\n___________________________\n");
}
