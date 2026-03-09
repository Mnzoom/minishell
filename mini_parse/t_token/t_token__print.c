/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:26:30 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/09 17:29:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_token__print(t_token *token)
{
	size_t	i;

	i = 0;
	printf("\n>> TOKEN\n");
	printf("token:\t\t");
	while (i < token->raw_len)
	{
		printf("%c", token->raw[i]);
		i++;
	}
	printf("\n");
	printf("type:\t\t%s\n", t_token_type__to_str(token->type));
	printf("value:\t\t%s\n", token->m_value);

}