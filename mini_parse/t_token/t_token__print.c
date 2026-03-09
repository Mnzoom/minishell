/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:26:30 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/09 16:27:04 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_token__print(t_token *token)
{
	size_t	i;

	i = 0;
	printf("\n>>>>>>>>>>>>> TOKEN:\n");
	printf("token:\t\t\t");
	while (i < token->raw_len)
	{
		printf("%c", token->raw[i]);
		i++;
	}
	printf("\n");
	printf("type:\t\t\t%d\n", token->type);
	printf("expanded:\t\t%s\n", token->m_expanded);

}