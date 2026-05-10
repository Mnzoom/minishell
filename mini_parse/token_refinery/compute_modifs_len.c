/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_modifs_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:43:06 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/10 09:20:27 by thantoni         ###   ########.fr       */
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

static size_t _compute_expansion_size(t_token *m_token, char *raw, t_env *m_env_list)
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

static void	_toggle_quote(t_token *m_token, int *quote_bool, int rm_quotes)
{
	if (rm_quotes)
		m_token->modifs_len--;
	*quote_bool = !*quote_bool;
}

void	compute_modifs_len(t_token *m_token, t_env *m_env_list, int exp, int rm_quotes)
{
	size_t	i;
	char	*raw;
	int		in_single;
	int		in_double;

	i = 0;
	raw = m_token->raw;
	in_single = FALSE;
	in_double = FALSE;
	while (raw[i] && i < m_token->raw_len)
	{
		if (rm_quotes && !in_single && raw[i] == '\\' && i + 1 < m_token->raw_len
			&& (!in_double || (raw[i + 1] == '$' || raw[i + 1] == '\"'
					|| raw[i + 1] == '\\')))
		{
			m_token->modifs_len--;
			i += 2;
		}
		else if (rm_quotes && !in_single && !in_double && raw[i] == '$' && i + 1 < m_token->raw_len
			&& (raw[i + 1] == '\'' || raw[i + 1] == '\"'))
		{
			m_token->modifs_len--;
			i++;
		}
		else if (exp && !in_single && (ft_issigpattern(&raw[i]) || (ft_isenvpattern(&raw[i]) && get_var_name_len(&raw[i + 1]) > 0)))
			i += _compute_expansion_size(m_token, &m_token->raw[i + 1], m_env_list);
		else
		{
			if (!in_double && raw[i] == '\'')
				_toggle_quote(m_token, &in_single, rm_quotes);
			else if (!in_single && raw[i] == '\"')
				_toggle_quote(m_token, &in_double, rm_quotes);
			i++;
		}
	}
}
