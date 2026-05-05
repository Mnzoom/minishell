/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_m_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:09:51 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/05 15:11:15 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "minishell.h"
#include "mini_exec.h"

char	*get_m_path(char *cmd, t_env *m_env_list)
{
	t_env	*path_node;
	char	**m_all_paths;
	char	*m_exec_path;
	int		i;

	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
		return (ft_strdup(cmd));
	path_node = t_env__get_by_key(m_env_list, "PATH");
	if (!path_node || !path_node->m_val)
		return (NULL);
	m_all_paths = ft_split(path_node->m_val, ':');
	if (m_all_paths == NULL)
		return (NULL);
	i = 0;
	while (m_all_paths[i])
	{
		m_exec_path = ft_strjoin3(m_all_paths[i], "/", cmd); //malloc
		if (access(m_exec_path, X_OK) == 0)
			return (ft_freearray(m_all_paths), m_exec_path);
		free(m_exec_path);
		i++;
	}
	return (ft_freearray(m_all_paths), NULL);
}
