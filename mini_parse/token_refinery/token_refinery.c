/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_refinery.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:52:38 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/09 17:22:43 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

int	_equal_until_delim(char *s1, char *s2, char s2_delim, size_t s1_stop)
{
	size_t              i;

	i = 0;
	while (s2[i + 1] != s2_delim && i < s1_stop && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s2[i + 1] == s2_delim && i + 1 == s1_stop && s1[i] == s2[i]);
}

size_t	_compute_var_name_len(char *var)
{
	size_t  i;

	i = 0;
	while (var[i] && ft_isalnum(var[i]))
		i++;
	return (i);
}

char	*_get_envp_var(char *var_start, char **envp)
{
	size_t  envp_i;
	size_t  var_name_len;

	if (var_start[0] == '$')
		var_start++;
	var_name_len = _compute_var_name_len(var_start);
	envp_i = 0;
	while(envp[envp_i])
	{
		if (ft_strncmp(var_start, envp[envp_i], var_name_len) == 0
			 && envp[envp_i][var_name_len] == '=')
		{
			return (envp[envp_i]);
		}
		envp_i++;
	}
	return (envp[envp_i]);
}

size_t	_compute_expansion_size(t_token *m_token, char *var_start, char **envp)
{
	size_t  envp_i;
	size_t  var_name_len;

	var_name_len = _compute_var_name_len(&var_start[1]);
	envp_i = 0;
	while(envp[envp_i])
	{
		if (_equal_until_delim(&var_start[1], envp[envp_i], '=', var_name_len))
		{
			size_t  skip_key = 0;
			while (envp[envp_i][skip_key] != '=')
				skip_key++;
			skip_key++;
			m_token->diff_len += ft_strlen(&envp[envp_i][skip_key]);
			break;
		}
		envp_i++;
	}
	m_token->diff_len -= var_name_len + 1;
	return (var_name_len + 1);
}

size_t	_insert_var(char *to_insert, char *var_start, char **envp)
{
	char    *envp_var;
	size_t  envp_i;
	size_t  insert_i;

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

void	_compute_total_len_diff(t_token *m_token, char **envp)
{
	size_t	i;
	char	*raw;

	i = 0;
	raw = m_token->raw;
	while(raw[i] && i < m_token->raw_len)
	{
		if (raw[i] == '$' && raw[i + 1] && raw[i + 1] != ' ' && raw[i + 1] != '$')
		{
			m_token->has_diff = TRUE;
			i += _compute_expansion_size(m_token, &m_token->raw[i], envp);
		}
		else
			i++;
	}
}

void _handle_expansion(t_token *m_token, char **envp)
{
	size_t	raw_i;
	size_t	exp_i;

	if (!m_token->has_diff)
		return ;
	m_token->m_value = malloc(sizeof(char) * (m_token->raw_len + m_token->diff_len + 1));
	if (m_token->m_value == NULL)
		return ;
	m_token->m_value[m_token->raw_len + m_token->diff_len] = '\0';
	raw_i = 0;
	exp_i = 0;
	while (m_token->raw[raw_i] && raw_i < m_token->raw_len)
	{
		if (m_token->raw[raw_i] == '$')
		{
			exp_i += _insert_var(&m_token->m_value[exp_i], &m_token->raw[raw_i + 1], envp);
			raw_i += _compute_var_name_len(&m_token->raw[raw_i + 1]) + 1;
		}
		else
		{
			m_token->m_value[exp_i] = m_token->raw[raw_i];
			raw_i++;
			exp_i++;
		}
	}
	printf("EXPANDED_TOKEN:\t%s\n", m_token->m_value);
}

void	token_refinery(t_token *m_token_list, char **envp)
{
	t_token	*token;

	token = m_token_list;
	while (token != NULL)
	{
		if (token->type == STR)
		{
			_compute_total_len_diff(token, envp);
			_handle_expansion(token, envp);
		}
		token = token->next;
	}
}

//TODO: '$USER' --print-> $USER
//TODO: $?swagin --print-> <code>swagin