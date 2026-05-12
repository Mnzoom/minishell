/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_expand_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 08:59:53 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 05:42:36 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

static size_t	_insert_var(char *holder, char *raw, \
	t_env *m_env_list, int in_double)
{
	t_env	*found;
	size_t	i;

	i = 0;
	found = t_env__get_by_key1(m_env_list, raw, get_var_name_len(raw));
	if (found != NULL)
	{
		while (found->m_val[i])
		{
			if (!in_double && (found->m_val[i] == ' '
					|| found->m_val[i] == '\t'))
				holder[i] = '\x1F';
			else
				holder[i] = found->m_val[i];
			i++;
		}
	}
	return (i);
}

void	modif_expand_env(t_token *m_token, t_env *m_env_list, \
	t_parse_info *info)
{
	info->exp_i += _insert_var(&m_token->m_value[info->exp_i],
			&m_token->raw[info->raw_i + 1], m_env_list, info->in_double);
	info->raw_i += get_var_name_len(&m_token->raw[info->raw_i + 1]) + 1;
}
