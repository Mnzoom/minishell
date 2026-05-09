/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_m_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:09:51 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/09 07:38:11 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "minishell.h"
#include "mini_exec.h"

char	*get_m_path(char *m_cmd, t_env *m_env_list)
{
	t_env	*m_node_path;
	char	**m_all_paths;
	char	*m_exec_path;
	int		i;

	if (m_cmd && (m_cmd[0] == '/' || m_cmd[0] == '.'))
		return (ft_strdup(m_cmd));
	m_node_path = t_env__get_by_key(m_env_list, "PATH");
	if (!m_node_path || !m_node_path->m_val)
		return (NULL);
	m_all_paths = ft_split(m_node_path->m_val, ':');
	if (m_all_paths == NULL)
		return (NULL);
	i = 0;
	while (m_all_paths[i])
	{
		m_exec_path = ft_strjoin3(m_all_paths[i], "/", m_cmd);
		if (access(m_exec_path, X_OK) == 0)
			return (ft_freearray(m_all_paths), m_exec_path);
		free(m_exec_path);
		i++;
	}
	return (ft_freearray(m_all_paths), NULL);
}
