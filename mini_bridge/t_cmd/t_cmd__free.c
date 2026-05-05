/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd__free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:57:17 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/05 18:01:53 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cmd.h"
#include "libft.h"
#include <stdlib.h>

void	t_cmd__free(t_cmd *m_cmd)
{
	if (m_cmd == NULL)
		return ;
	if (m_cmd->m_args != NULL)
		t_gc__free1(m_cmd->m_args);
	t_redirect__freeall(m_cmd->m_redirect_list);
	t_gc__free1(m_cmd);
}
