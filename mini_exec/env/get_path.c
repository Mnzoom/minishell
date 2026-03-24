/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:09:51 by clementngoi       #+#    #+#             */
/*   Updated: 2026/03/23 14:44:46 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "minishell.h"
#include "mini_exec.h"


static char *join_path_cmd(char *path, char *cmd)
{
    char *tmp;
    char *full;

    tmp = strjoin(path, "/");
    if(!tmp)
        return (NULL);
    full = ft_strjoin(tmp, cmd);
    free(tmp);
    return(full);
}

char *get_path(char *cmd, t_env *m_env_list)
{
    t_env *path_node;
    char **all_paths;
    char *exec_path;
    int i;

    if(cmd && (cmd[0] == '/' || cmd[0] == '.'))
        return(ft_strdup(cmd));
    path_node = t_env__get_by_key(m_env_list, "PATH");
    if(!path_node || !path_node->m_val)
        return (NULL);
    all_paths = ft_split(path_node->m_val, ':');
    i = 0;
    while (all_paths && all_paths[i])
    {
        exec_path = join_path_cmd(all_paths[i], cmd);
        if (access(exec_path, X_OK) == 0)
        {
            ft_freesplit();
            return (exec_path);
        }
        free(exec_path);
        i++;
    }
    return (NULL);
    
}