/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:16:53 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/06 13:19:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXEC_H
# define MINI_EXEC_H

# include <unistd.h>  
# include <fcntl.h>
# include <readline/readline.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "mini_bridge.h"

/* BUILTIN GESTION*/
int		is_builtin(char *cmd);
int		exec_builtin(t_cmd *cmd, t_env **env_list);

/* OH LA TUILE*/
int		apply_redirections(t_redirect *redir_list);
char	**env_to_tab(t_env *env_list);
char	*get_m_path(char *cmd, t_env *m_env_list);
int		read_heredoc(char *lim);

/* EXEC*/
void	exec_child_process(t_cmd *cmd, t_env *env_list);
// void	exec_cmds(t_cmd *cmd_list, t_env **env_list);
int		exec_pipe(t_cmd *cmd_list, t_env *env_list);

char	*get_m_path(char *cmd, t_env *m_env_list);
int		read_heredoc(char *lim);
int		mini_export(char **args, t_env **env_list, int fd);

#endif