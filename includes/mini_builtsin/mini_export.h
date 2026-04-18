/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:17:02 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/18 12:45:19 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXPORT_H
# define MINI_EXPORT_H

# include "minishell.h"
# include "libft.h"

int		handle_env_sorted_print(t_env *m_env_list, int fd);
int		handle_env_export( t_env **m_env_list, char *arg);
int	is_valid_identifier(char *str);

#endif