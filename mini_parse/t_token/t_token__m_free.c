/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__m_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:08:12 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/10 15:07:29 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_token__m_free(t_token *m_token, int destroy_value)
{
	if (m_token == NULL)
		return ;
	if (destroy_value && m_token->m_value != NULL)
		free(m_token->m_value);
	free(m_token);
}
