/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modifs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:40:23 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/01 20:15:37 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

extern int g_lastsignal;

static size_t	_insert_var(char *holder, char *var_start, t_env *m_env_list)
{
	t_env	*m_found_env;
	size_t	insert_i;

	insert_i = 0;
	m_found_env = t_env__get_by_key1(m_env_list, var_start, get_var_name_len(var_start));
	if (m_found_env != NULL)
	{
		while (m_found_env->m_val[insert_i])
		{
			holder[insert_i] = m_found_env->m_val[insert_i];
			insert_i++;
		}
	}
	return (insert_i);
}

static void	_expand_env(t_token *m_token, t_env *env, size_t *raw_i, size_t *exp_i)
{
	*exp_i += _insert_var(&m_token->m_value[*exp_i], &m_token->raw[*raw_i + 1], env);
	*raw_i += get_var_name_len(&m_token->raw[*raw_i + 1]) + 1;
}

static size_t _insert_sig(char *holder)
{
	size_t	len;
	size_t	i;
	long	num;

	num = g_lastsignal;
	len = get_lastsig_len();
	i = len;
	if (num < 0)
	{
		holder[0] = '-';
		num = -num;
	}
	if (num == 0)
		holder[0] = '0';
	while (num > 0)
	{
		i--;
		holder[i] = (num % 10) + '0';
		num = num / 10;
	}
	return (len);
}

static void	_expand_sig(t_token *m_token, size_t *raw_i, size_t *exp_i)
{
	*exp_i += _insert_sig(&m_token->m_value[*exp_i]);
	*raw_i += 1 + 1;
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

//compute_modifs_len
//
//handle_modifs
//- malloc pour:
//	1. modifs_len
//
//- fill malloc
//	1. get_env
//	2. sig
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
		if (!in_single && ft_isenvpattern(&m_token->raw[raw_i]))
			_expand_env(m_token, m_env_list, &raw_i, &exp_i);
		else if (!in_single && ft_issigpattern(&m_token->raw[raw_i]))
			_expand_sig(m_token, &raw_i, &exp_i);
		else if (raw_i < m_token->raw_len)
		{
			m_token->m_value[exp_i] = m_token->raw[raw_i];
			raw_i++;
			exp_i++;
		}
	}
	m_token->is_ignored = exp_i == 0;
}
