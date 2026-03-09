/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:52:38 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/09 16:25:00 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

size_t _compute_var_name_len(char *var)
{
    size_t i;

    i = 0;
    if (var[i] == '?')
        return (1);
    while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
        i++;
    return (i);
}

char *_get_envp_var(char *var_start, char **envp)
{
    size_t envp_i;
    size_t v_len;

    if (var_start[0] == '$')
        var_start++;
    v_len = _compute_var_name_len(var_start);
    if (v_len == 0)
        return (NULL);
    envp_i = 0;
    while (envp[envp_i])
    {
        if (ft_strncmp(var_start, envp[envp_i], v_len) == 0 
            && envp[envp_i][v_len] == '=')
            return (envp[envp_i]);
        envp_i++;
    }
    return (NULL);
}

size_t _compute_expansion_size(t_token *m_token, char *v_start, char **envp)
{
    char    *env_str;
    size_t  v_len;
    size_t  val_len;

    v_len = _compute_var_name_len(&v_start[1]);
    env_str = _get_envp_var(v_start, envp);
    val_len = 0;
    if (env_str != NULL)
    {
        while (env_str[val_len] != '=')
            env_str++;
        env_str++;
        val_len = ft_strlen(env_str);
    }
    m_token->expanded_len += val_len;
    m_token->expanded_len -= (v_len + 1);
    return (v_len + 1);
}

size_t _insert_var(char *to_insert, char *v_start, char **envp)
{
    char    *env_str;
    size_t  i;

    i = 0;
    env_str = _get_envp_var(v_start, envp);
    if (env_str == NULL)
        return (0);
    while (*env_str != '=')
        env_str++;
    env_str++;
    while (env_str[i])
    {
        to_insert[i] = env_str[i];
        i++;
    }
    return (i);
}

int _is_expandable(char *raw, size_t i, int in_single)
{
    if (raw[i] == '$' && !in_single && raw[i + 1])
    {
        if (raw[i + 1] != ' ' && raw[i + 1] != '"' && raw[i + 1] != '\'')
            return (1);
    }
    return (0);
}

void _calc_exp_len(t_token *tok, char **envp)
{
    size_t  i;
    int     in_s;
    int     in_d;

    i = 0;
    in_s = 0;
    in_d = 0;
    while (tok->raw[i] && i < tok->raw_len)
    {
        if (tok->raw[i] == '\'' && !in_d)
            in_s = !in_s;
        else if (tok->raw[i] == '"' && !in_s)
            in_d = !in_d;
        if (_is_expandable(tok->raw, i, in_s))
        {
            tok->has_expansion = 1;
            i += _compute_expansion_size(tok, &tok->raw[i], envp);
            continue;
        }
        i++;
    }
}

void _fill_expansion(t_token *tok, char **envp)
{
    size_t  r_i;
    size_t  e_i;
    int     in_s;
    int     in_d;

    r_i = 0;
    e_i = 0;
    in_s = 0;
    in_d = 0;
    while (tok->raw[r_i] && r_i < tok->raw_len)
    {
        if (tok->raw[r_i] == '\'' && !in_d)
            in_s = !in_s;
        else if (tok->raw[r_i] == '"' && !in_s)
            in_d = !in_d;
        if (_is_expandable(tok->raw, r_i, in_s))
        {
            e_i += _insert_var(&tok->m_expanded[e_i], &tok->raw[r_i + 1], envp);
            r_i += _compute_var_name_len(&tok->raw[r_i + 1]) + 1;
            continue;
        }
        tok->m_expanded[e_i++] = tok->raw[r_i++];
    }
}

void _handle_expansion(t_token *tok, char **envp)
{
    _calc_exp_len(tok, envp);
    if (!tok->has_expansion)
        return;
    tok->m_expanded = malloc(sizeof(char) * (tok->raw_len + tok->expanded_len + 1));
    if (tok->m_expanded == NULL)
        return;
    _fill_expansion(tok, envp);
    tok->m_expanded[tok->raw_len + tok->expanded_len] = '\0';
}

void token_expander(t_token *m_token_list, char **envp)
{
    t_token *token;

    token = m_token_list;
    while (token != NULL)
    {
        if (token->type == STR)
            _handle_expansion(token, envp);
        token = token->next;
    }
}

//TODO: '$USER' --print-> $USER
//TODO: $?swagin --print-> <code>swagin