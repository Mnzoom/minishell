/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd__m_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:42:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/11 15:46:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

t_cmd	*t_cmd__m_new(size_t arg_count)
{
	t_cmd	*m_cmd;

	m_cmd = malloc(sizeof(t_cmd));
	if (m_cmd == NULL)
		return (NULL);
	m_cmd->m_args = malloc(sizeof(char *) * (arg_count + 1));
	if (m_cmd->m_args == NULL)
		return (NULL);
	m_cmd->m_args[arg_count] = NULL;
	m_cmd->m_redirect_list = NULL;
	m_cmd->next = NULL;
	return (m_cmd);
}
