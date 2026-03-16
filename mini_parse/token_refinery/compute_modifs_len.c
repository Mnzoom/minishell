/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_modifs_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:43:06 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/16 12:47:48 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

static size_t	_compute_var_name_len(char *var)
{
	size_t	i;

	i = 0;
	while (var[i] && ft_isalnum(var[i]))
		i++;
	return (i);
}

static int	_equal_until_delim(char *s1, char *s2, char s2_delim, size_t s1_stop)
{
	size_t	i;

	i = 0;
	while (s2[i + 1] != s2_delim && i < s1_stop && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s2[i + 1] == s2_delim && i + 1 == s1_stop && s1[i] == s2[i]);
}

static size_t	_compute_expansion_size(t_token *m_token, char *var_start, char **envp)
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

static void	_toggle_quote(t_token *m_token, int *quote_bool)
{
	m_token->modifs_len--;
	*quote_bool = !*quote_bool;
}

void	compute_modifs_len(t_token *m_token, char **envp)
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
