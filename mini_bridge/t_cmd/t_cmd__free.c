/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd__free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:57:17 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/01 22:05:07 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cmd.h"
#include "libft.h"

void	t_cmd__free(t_cmd *m_cmd)
{
	if (m_cmd == NULL)
		return ;
	ft_freearray(m_cmd->m_args);
	t_redirect__freeall(m_cmd->m_redirect_list);
}