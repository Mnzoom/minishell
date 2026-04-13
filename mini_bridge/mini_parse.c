/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:59:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/13 14:56:36 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

t_cmd	*mini_parse(char *line, t_env *m_env_list)
{
	t_token	*m_token_list;
	t_cmd	*m_cmd_list;
	m_token_list = tokenize(line);
	if (!token_verifier(m_token_list))
		return (NULL);
	token_refinery(m_token_list, m_env_list);
	m_cmd_list = cmd_shipper(m_token_list);
	t_token__m_free_all(m_token_list, FALSE);
	return (m_cmd_list);
}
