/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modifs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:40:23 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 09:31:49 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

static int	_handle_escape(t_token *m_token, t_parse_info *info)
{
	if (info->rm_quotes && !info->in_single && m_token->raw[info->raw_i] == '\\'
		&& info->raw_i + 1 < m_token->raw_len && (!info->in_double
			|| (m_token->raw[info->raw_i + 1] == '$'
				|| m_token->raw[info->raw_i + 1] == '\"'
				|| m_token->raw[info->raw_i + 1] == '\\')))
	{
		info->raw_i++;
		m_token->m_value[info->exp_i++] = m_token->raw[info->raw_i++];
		return (1);
	}
	return (0);
}

static int	_handle_quotes(t_token *m_token, t_parse_info *info)
{
	size_t	skip_len;

	if ((m_token->raw[info->raw_i] == '\'' && !info->in_double)
		|| (m_token->raw[info->raw_i] == '\"' && !info->in_single))
		info->has_quotes = 1;
	if (info->rm_quotes)
	{
		skip_len = modif_handle_quote_skip(&m_token->raw[info->raw_i],
				&info->in_single, &info->in_double);
		info->raw_i += skip_len;
		if (skip_len > 0)
			return (1);
	}
	else if (m_token->raw[info->raw_i] == '\'' && !info->in_double)
		info->in_single = !info->in_single;
	else if (m_token->raw[info->raw_i] == '\"' && !info->in_single)
		info->in_double = !info->in_double;
	return (0);
}

static void	_process_char(t_token *m_token, t_env *m_env_list, t_parse_info *info)
{
	if (_handle_escape(m_token, info))
		return ;
	if (info->rm_quotes && !info->in_single && !info->in_double && m_token->raw[info->raw_i] == '$'
		&& info->raw_i + 1 < m_token->raw_len && (m_token->raw[info->raw_i + 1] == '\''
			|| m_token->raw[info->raw_i + 1] == '\"'))
		info->raw_i++;
	if (_handle_quotes(m_token, info))
		return ;
	if (info->is_exp && !info->in_single && ft_isenvpattern(&m_token->raw[info->raw_i])
		&& get_var_name_len(&m_token->raw[info->raw_i + 1]) > 0)
		modif_expand_env(m_token, m_env_list, info);
	else if (info->is_exp && !info->in_single && ft_issigpattern(&m_token->raw[info->raw_i]))
		modif_expand_sig(m_token, info);
	else if (info->raw_i < m_token->raw_len)
		m_token->m_value[info->exp_i++] = m_token->raw[info->raw_i++];
}

void	handle_modifs(t_token *m_token, t_env *m_env_list, int exp, int rm_quotes)
{
	t_parse_info	info;

	if (!ft_malloc((void **)&m_token->m_value,
			sizeof(char) * (m_token->raw_len + m_token->modifs_len + 1)))
		return ;
	info = (t_parse_info) { 0 };
	info.is_exp = exp;
	info.rm_quotes = rm_quotes;
	while (m_token->raw[info.raw_i] && info.raw_i < m_token->raw_len)
		_process_char(m_token, m_env_list, &info);
	m_token->m_value[info.exp_i] = '\0';
	m_token->is_ignored = (info.exp_i == 0 && !info.has_quotes);
	m_token->had_quotes = info.has_quotes;
}
