/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_bridge.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:17:09 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/05 16:45:35 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BRIDGE_H
# define MINI_BRIDGE_H

/** @brief Parsing data result. Ready to use for execution */
typedef struct s_cmd
{
	char			**args;
	char			*infile;
	char			*outfile;

	/** @brief Output mode, can be "TRUE (APPEND)" or "FALSE (OVERRIDE)" */
	int				is_append_mode;
	/** @brief Input mode, can be "TRUE (HEREDOC)" or "FALSE (READ)" */
	int				is_heredoc_mode;

	struct s_cmd	*next;
}	t_cmd;

#endif