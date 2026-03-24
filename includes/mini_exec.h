/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:16:53 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/23 13:40:17 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXEC_H
# define MINI_EXEC_H

# include "mini_bridge.h"
# include <unistd.h>  
#include <fcntl.h>
#include <readline/readline.h>

void    apply_redirections(t_redirect *redir_list);
int is_builtin(char *cmd);
int exec_builtin(t_cmd *cmd, t_env **env_list);
char    **env_to_tab(t_env *env_list);
void    exec_child_process(t_cmd *cmd, t_env *env_list);
void    exec_cmds(t_cmd *cmd_list, t_env **env_list);
char *get_path(char *cmd, t_env *m_env_list);
int read_heredoc(char *lim);

#endif