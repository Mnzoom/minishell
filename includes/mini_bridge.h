/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_bridge.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:17:09 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 14:48:02 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BRIDGE_H
# define MINI_BRIDGE_H

# include <stddef.h>
# include <stdlib.h>

# define EXIT_SUCCESS 0
# define EXIT_ERROR 1
# define TRUE 1
# define FALSE 0

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

t_cmd	*mini_parse(char *line);
void	mini_exec(t_cmd *cmd_linked_list);


#endif