/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_info.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 04:11:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 04:24:05 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HEREDOC_INFO_H
# define T_HEREDOC_INFO_H

# include "t_redirect.h"
# include "t_line_input.h"
# include "t_env.h"

typedef struct s_heredoc_info
{
	t_redirect		*m_red;
	t_env			*m_env;
	t_line_input	*input;
	int				tmp_fd;
	int				start_i;
	int				l_count;
	int				found;
	int				is_int;
}	t_heredoc_info;

t_heredoc_info	t_heredoc_info__init(t_redirect *m_red, t_env *m_env_list, \
	t_line_input *input);

#endif