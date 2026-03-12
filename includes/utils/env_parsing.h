/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:31:23 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/12 12:46:24 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_PARSING_H
# define ENV_PARSING_H

# include "stddef.h"

char	*env_extract_m_value(char *env_var);
char	*env_extract_m_key(char *env_var);
int		env_is_key_valid(char *key);

#endif