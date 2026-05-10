/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 06:51:07 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 08:37:23 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

static void	_link_nodes(t_token *m_node, t_token *m_og, t_token **m_start, char **sp)
{
	if (m_node)
		m_node->next = m_og->next;
	if (m_og->next)
		m_og->next->prev = m_node;
	if (!sp[0] && !m_node && m_og->next)
		*m_start = m_og->next;
	else if (!sp[0] && !m_node && !m_og->next)
		*m_start = NULL;
}

static void	_insert_new_nodes(t_token *m_og, char **m_val_split, t_token **m_token_list)
{
	t_token	*m_node;
	t_token	*new_n;
	int		i;

	m_node = m_og->prev;
	i = 0;
	while (m_val_split[i])
	{
		new_n = t_token__m_new(NULL, 0, STR);
		new_n->m_value = ft_strdup(m_val_split[i]);
		new_n->had_quotes = m_og->had_quotes;
		new_n->prev = m_node;
		if (m_node)
			m_node->next = new_n;
		else
			*m_token_list = new_n;
		m_node = new_n;
		i++;
	}
	_link_nodes(m_node, m_og, m_token_list, m_val_split);
}

void	token_splitter(t_token **m_token_list)
{
	t_token	*m_node;
	t_token	*m_tmp_next;
	char	**m_val_split;

	m_node = *m_token_list;
	while (m_node)
	{
		m_tmp_next = m_node->next;
		if (m_node->type == STR && ft_strchr(m_node->m_value, '\x1F'))
		{
			m_val_split = ft_split(m_node->m_value, '\x1F');
			if (m_val_split)
			{
				_insert_new_nodes(m_node, m_val_split, m_token_list);
				ft_freearray(m_val_split);
				t_token__m_free(m_node);
			}
		}
		m_node = m_tmp_next;
	}
}