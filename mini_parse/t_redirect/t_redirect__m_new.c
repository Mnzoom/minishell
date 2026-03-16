/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redirect__m_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:05:37 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:03:52 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"

t_redirect	*t_redirect__m_new(char *m_name, t_token_type type)
{
	t_redirect	*m_redirect;

	m_redirect = malloc(sizeof(t_redirect));
	m_redirect->m_value = m_name;
	m_redirect->type = type;
	m_redirect->next = NULL;
	return (m_redirect);
}
