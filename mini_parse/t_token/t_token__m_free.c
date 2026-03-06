/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token__m_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:08:12 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 18:51:40 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

void	t_token__m_free(t_token *m_token)
{
	if (m_token == NULL)
		return ;
	if (m_token->m_expanded != NULL)
		free(m_token->m_expanded);
	free(m_token);
}
