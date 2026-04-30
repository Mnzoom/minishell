/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export__internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:17:02 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 19:34:33 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXPORT__INTERNAL_H
# define MINI_EXPORT__INTERNAL_H

# include "minishell.h"
# include "libft.h"

int		handle_env_sorted_print(t_env *m_env_list, int fd);
int		handle_env_export( t_env **m_env_list, char *arg);
int		is_valid_identifier(char *str);

#endif