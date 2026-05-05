/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd__print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:47:55 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/05 16:29:28 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_cmd__print(t_cmd *cmd)
{
	size_t		i;
	t_redirect	*m_redirect;

	printf("\n___________ CMD ___________\n");
	m_redirect = cmd->m_redirect_list;
	if (m_redirect != NULL)
	{
		printf("\nredirects\t:\n");
		while (m_redirect != NULL)
		{
			printf(" (%s)\t  %s\n", t_token_type__to_str(m_redirect->type), m_redirect->m_value);
			m_redirect = m_redirect->next;
		}
	}
	i = 0;
	printf("\nargs\t\t: ");
	while (cmd->m_args[i] != NULL)
	{
		printf("(%p)%s ", &cmd->m_args[i], cmd->m_args[i]);
		i++;
	}
	printf("\n");
	printf("\n___________________________\n");
}
