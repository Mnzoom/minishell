/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env__to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:54:59 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 18:07:18 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "mini_exec.h"
#include "t_env.h"

char	**t_env__to_array(t_env *m_env_list)
{
	t_env	*node;
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * (t_env__get_size(m_env_list) + 1));
	if (!array)
		return (NULL);
	node = m_env_list;
	i = 0;
	while (node != NULL)
	{
		array[i] = ft_strjoin3(node->m_key, "=", node->m_val);
		node = node->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
