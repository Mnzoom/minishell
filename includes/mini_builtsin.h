/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_builtsin.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:43:16 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 17:35:10 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BUILTSIN_H
# define MINI_BUILTSIN_H

# include "minishell.h"

int		is_builtin(char *cmd);
int		mini_echo(char **args);
int		mini_cd(char **args, t_env **env_list);
int		mini_pwd(t_env *env_list);
int		builtin_export(char **args, t_env **env_list);
int		mini_unset(char **args, t_env **env_list);
int		builtin_env(t_env *env_list);
int		mini_exit(char **args);

#endif