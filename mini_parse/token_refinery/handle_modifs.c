/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modifs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:40:23 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 15:58:23 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

static size_t	_insert_var(char *to_insert, char *var_start, t_env *m_env_list)
{
	t_env	*m_found_env;
	size_t	insert_i;

	insert_i = 0;
	m_found_env = t_env__get_by_key1(m_env_list, var_start, get_var_name_len(var_start));
	if (m_found_env != NULL)
	{
		while (m_found_env->m_val[insert_i])
		{
			to_insert[insert_i] = m_found_env->m_val[insert_i];
			insert_i++;
		}
	}
	return (insert_i);
}

static size_t	_skip(char *raw, char c_quote, int *bool)
{
	size_t	skip_i;

	skip_i = 0;
	while (raw[skip_i] == c_quote)
	{
		*bool = !*bool;
		skip_i++;
	}
	return (skip_i);
}

static size_t	_handle_quote_skip(char *raw, int *in_single, int *in_double)
{
	size_t	skip_i;

	skip_i = 0;
	while ((raw[skip_i] == '\'' && !*in_double) || (raw[skip_i] == '\"' && !*in_single))
	{
		if (raw[skip_i] == '\'' && !*in_double)
			skip_i += _skip(&raw[skip_i], '\'', in_single);
		else if (raw[skip_i] == '\"' && !*in_single)
			skip_i += _skip(&raw[skip_i], '\"', in_double);
	}
	return (skip_i);
}

static void	_expand_dollar(t_token *m_token, t_env *env, size_t *raw_i, size_t *exp_i)
{
	*exp_i += _insert_var(&m_token->m_value[*exp_i], &m_token->raw[*raw_i + 1], env);
	*raw_i += get_var_name_len(&m_token->raw[*raw_i + 1]) + 1;
}

void	handle_modifs(t_token *m_token, t_env *m_env_list)
{
	size_t	raw_i;
	size_t	exp_i;
	int		in_single;
	int		in_double;

	if (!ft_malloc((void **)&m_token->m_value, sizeof(char) * (m_token->raw_len + m_token->modifs_len)))
		return ;
	raw_i = 0;
	exp_i = 0;
	in_single = FALSE;
	in_double = FALSE;
	while (m_token->raw[raw_i] && raw_i < m_token->raw_len)
	{
		raw_i += _handle_quote_skip(&m_token->raw[raw_i], &in_single, &in_double);
		if (in_single || m_token->raw[raw_i] != '$')
		{
			m_token->m_value[exp_i] = m_token->raw[raw_i];
			raw_i++;
			exp_i++;
		}
		else
			_expand_dollar(m_token, m_env_list, &raw_i, &exp_i);
	}
}
