/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_refinery.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:52:38 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/10 14:28:13 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

int	_equal_until_delim(char *s1, char *s2, char s2_delim, size_t s1_stop)
{
	size_t	i;

	i = 0;
	while (s2[i + 1] != s2_delim && i < s1_stop && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s2[i + 1] == s2_delim && i + 1 == s1_stop && s1[i] == s2[i]);
}

size_t	_compute_var_name_len(char *var)
{
	size_t	i;

	i = 0;
	while (var[i] && ft_isalnum(var[i]))
		i++;
	return (i);
}

char	*_get_envp_var(char *var_start, char **envp)
{
	size_t	envp_i;
	size_t	var_name_len;

	if (var_start[0] == '$')
		var_start++;
	var_name_len = _compute_var_name_len(var_start);
	envp_i = 0;
	while (envp[envp_i])
	{
		if (ft_strncmp(var_start, envp[envp_i], var_name_len) == 0 && envp[envp_i][var_name_len] == '=')
		{
			return (envp[envp_i]);
		}
		envp_i++;
	}
	return (envp[envp_i]);
}

size_t	_compute_expansion_size(t_token *m_token, char *var_start, char **envp)
{
	size_t	envp_i;
	size_t	var_name_len;
	size_t	skip_key;

	var_name_len = _compute_var_name_len(&var_start[1]);
	envp_i = 0;
	while (envp[envp_i])
	{
		if (_equal_until_delim(&var_start[1], envp[envp_i], '=', var_name_len))
		{
			skip_key = 0;
			while (envp[envp_i][skip_key] != '=')
				skip_key++;
			skip_key++;
			m_token->modifs_len += ft_strlen(&envp[envp_i][skip_key]);
			break ;
		}
		envp_i++;
	}
	m_token->modifs_len -= var_name_len + 1;
	return (var_name_len + 1);
}

size_t	_insert_var(char *to_insert, char *var_start, char **envp)
{
	char	*envp_var;
	size_t	envp_i;
	size_t	insert_i;

	(void)to_insert, (void)var_start, (void)envp;
	envp_i = 0;
	insert_i = 0;
	envp_var = _get_envp_var(var_start, envp);
	if (envp_var == NULL)
		return (insert_i);
	while (envp_var[envp_i] != '=')
		envp_i++;
	envp_i++;
	while (envp_var[envp_i + insert_i])
	{
		to_insert[insert_i] = envp_var[envp_i + insert_i];
		insert_i++;
	}
	return (insert_i);
}

void	_toggle_quote(t_token *m_token, int *quote_bool)
{
	m_token->modifs_len--;
	*quote_bool = !*quote_bool;
}

void	_compute_modifs_len(t_token *m_token, char **envp)
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
		if (!in_single && raw[i] == '$' && raw[i + 1] && raw[i + 1] != ' ' && raw[i + 1] != '$')
			i += _compute_expansion_size(m_token, &m_token->raw[i], envp);
		else
		{
			if (!in_double && raw[i] == '\'')
				_toggle_quote(m_token, &in_single);
			else if (!in_single && raw[i] == '\"')
				_toggle_quote(m_token, &in_double);
			i++;
		}
	}
}

size_t	_skip(char *raw, char c_quote, int *bool)
{
	size_t	skip_i;

	skip_i = 0;
	while (raw[skip_i] == c_quote)
	{
		printf("in loop for char [%c]\n", c_quote);
		*bool = !*bool;
		skip_i++;
	}
	return (skip_i);
}

size_t	_handle_quote_skip(char *raw, int *in_single, int *in_double)
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

void _handle_modifs(t_token *m_token, char **envp)
{
	size_t	raw_i;
	size_t	exp_i;
	size_t	skip_i;
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
		skip_i = _handle_quote_skip(&m_token->raw[raw_i], &in_single, &in_double);
		raw_i += skip_i;
		if (in_single || m_token->raw[raw_i] != '$')
		{
			m_token->m_value[exp_i] = m_token->raw[raw_i];
			raw_i++;
			exp_i++;
		}
		else if (!in_single)
		{
			exp_i += _insert_var(&m_token->m_value[exp_i], &m_token->raw[raw_i + 1], envp);
			raw_i += _compute_var_name_len(&m_token->raw[raw_i + 1]) + 1;
		}
		else
			raw_i++;
	}
}

void	token_refinery(t_token *m_token_list, char **envp)
{
	t_token	*token;

	token = m_token_list;
	while (token != NULL)
	{
		if (token->type == STR)
		{
			_compute_modifs_len(token, envp);
			_handle_modifs(token, envp);
		}
		token = token->next;
	}
}

//TODO: $?swagin --print-> <code>swagin
//TODO: '$USER' --print-> $USER
//Quand " open alors ignore '