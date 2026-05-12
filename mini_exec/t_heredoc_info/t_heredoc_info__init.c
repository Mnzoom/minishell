/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_info__init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 04:15:04 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 11:18:29 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc_info.h"

t_heredoc_info	t_heredoc_info__init(t_redirect *m_red, t_env *m_env_list, \
	t_line_input *input)
{
	t_heredoc_info	info;

	info = (t_heredoc_info){0};
	info.m_red = m_red;
	info.m_env = m_env_list;
	info.input = input;
	return (info);
}
