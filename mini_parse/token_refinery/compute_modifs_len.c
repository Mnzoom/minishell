/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_modifs_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:43:06 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 14:40:42 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

static size_t	_exp_sig(t_token *m_token)
{
	size_t	lastsig_len;

	lastsig_len = get_lastsig_len();
	m_token->modifs_len += lastsig_len - 2;
	return (2);
}

static size_t	_compute_expansion_size(t_token *m_token, char *raw, \
	t_env *m_env_list)
{
	size_t	var_name_len;
	t_env	*m_found_env;

	if (raw[0] == '?')
		return (_exp_sig(m_token));
	var_name_len = get_var_name_len(raw);
	m_found_env = t_env__get_by_key1(m_env_list, raw, var_name_len);
	if (m_found_env != NULL)
		m_token->modifs_len += m_found_env->val_len - (var_name_len + 1);
	else
		m_token->modifs_len += -(var_name_len + 1);
	return (var_name_len + 1);
}

static int	_handle_escape_chars(t_token *m_token, t_parse_info *info)
{
	char	c_next;

	if (!info->rm_quotes || info->in_single \
		|| info->raw_i + 1 >= m_token->raw_len)
		return (FALSE);
	c_next = m_token->raw[info->raw_i + 1];
	if (m_token->raw[info->raw_i] == '\\')
	{
		if (!info->in_double || c_next == '$' \
			|| c_next == '\"' || c_next == '\\')
		{
			m_token->modifs_len--;
			info->raw_i += 2;
			return (TRUE);
		}
	}
	else if (!info->in_double && m_token->raw[info->raw_i] == '$')
	{
		if (c_next == '\'' || c_next == '\"')
			return (m_token->modifs_len--, info->raw_i++, TRUE);
	}
	return (FALSE);
}

static void	_process_char_len(t_token *m_token, t_env *m_env_list, \
	t_parse_info *info)
{
	if (_handle_escape_chars(m_token, info))
		return ;
	if (info->is_exp && !info->in_single
		&& (ft_issigpattern(&m_token->raw[info->raw_i])
			|| (ft_isenvpattern(&m_token->raw[info->raw_i])
				&& get_var_name_len(&m_token->raw[info->raw_i + 1]) > 0)))
		info->raw_i += _compute_expansion_size(m_token, \
			&m_token->raw[info->raw_i + 1], m_env_list);
	else
	{
		if (!info->in_double && m_token->raw[info->raw_i] == '\'')
		{
			if (info->rm_quotes)
				m_token->modifs_len--;
			info->in_single = !info->in_single;
		}
		else if (!info->in_single && m_token->raw[info->raw_i] == '\"')
		{
			if (info->rm_quotes)
				m_token->modifs_len--;
			info->in_double = !info->in_double;
		}
		info->raw_i++;
	}
}

void	compute_modifs_len(t_token *m_token, t_env *m_env_list, \
	int exp, int rm_quotes)
{
	t_parse_info	info;

	info = t_parse_info__init(exp, rm_quotes);
	while (m_token->raw[info.raw_i] && info.raw_i < m_token->raw_len)
		_process_char_len(m_token, m_env_list, &info);
}
