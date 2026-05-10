/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__to_m_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:54:59 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 09:38:38 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"
#include "t_env.h"

char	**t_env__to_m_array(t_env *m_env_list)
{
	t_env	*m_node;
	char	**m_array;
	int		i;

	m_array = malloc(sizeof(char *) * (t_env__get_size(m_env_list) + 1));
	if (!m_array)
		return (NULL);
	m_node = m_env_list;
	i = 0;
	while (m_node != NULL)
	{
		if (m_node->m_val != NULL)
		{
			m_array[i] = ft_strjoin3(m_node->m_key, "=", m_node->m_val);
			i++;
		}
		m_node = m_node->next;
	}
	m_array[i] = NULL;
	return (m_array);
}
