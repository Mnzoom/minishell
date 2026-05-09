/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:16:53 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/09 07:39:22 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXEC_H
# define MINI_EXEC_H

# include <unistd.h>  
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "mini_bridge.h"

int		is_builtin(char *cmd);
int		exec_builtin(t_cmd *m_cmd, t_env **m_env_list);

int		apply_redirections(t_redirect *m_red_list);
char	*get_m_path(char *cmd, t_env *m_env_list);

void	exec_child_process(t_cmd *m_cmd_list, t_env *env_list);
int		exec_pipe(t_cmd *m_cmd_list, t_env *m_env_list);
int		handle_heredocs(t_cmd *m_cmd_list, t_env *m_env_list, t_line_input *input);

char	*get_m_path(char *cmd, t_env *m_env_list);
int		mini_export(char **args, t_env **env_list, int fd);

#endif