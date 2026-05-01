/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redirect__free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:46:58 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/01 21:57:48 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_redirect.h"
#include <stdlib.h>

void	t_redirect__free(t_redirect *m_redirect)
{
	if (m_redirect == NULL)
		return;
	if (m_redirect->m_value != NULL)
		free(m_redirect->m_value);
	free(m_redirect);
}