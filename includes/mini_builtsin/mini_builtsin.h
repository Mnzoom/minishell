/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_builtsin.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:43:16 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/12 12:30:13 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BUILTSIN
# define MINI_BUILTSIN

# include "minishell.h"

int	mini_echo(char **args, int fd);
int	mini_unset(char **args, t_env **env_list);
int	mini_export(char **args, int fd);

#endif