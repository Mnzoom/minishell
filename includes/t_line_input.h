/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_line_input.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 04:12:27 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 04:12:49 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LINE_INPUT_H
# define T_LINE_INPUT_H

typedef struct s_line_input
{
	char	**m_lines;
	int		current;
	int		count;
}	t_line_input;

#endif