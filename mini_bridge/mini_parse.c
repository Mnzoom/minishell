/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:59:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 16:56:29 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "mini_parse.h"
#include "libft.h"
#include <stdio.h>

t_token	*get_current_token(char *line)
{
    if (line[0] == '>' && line[1] == '>')
        return (t_token__m_new(line, 2, APPEND));
    if (line[0] == '<' && line[1] == '<')
        return (t_token__m_new(line, 2, HEREDOC));
    if (line[0] == '|')
        return (t_token__m_new(line, 1, PIPE));
    if (line[0] == '>')
        return (t_token__m_new(line, 1, OVERRIDE));
    if (line[0] == '<')
        return (t_token__m_new(line, 1, INFILE));
    return (t_token__parse_value_str(line));
}

t_token	*tokenize(char *line)
{
	size_t	i;
	t_token	*first;
	t_token	*last;
	t_token	*current;

	i = 0;
	first = NULL;
	last = NULL;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '\0')
			break;
		current = get_current_token(&line[i]);
		if (current == NULL)
			return (NULL); //TODO: free first
		if (first == NULL)
			first = current;
		else
			last->next = current;
		last = current;
		i += current->len;
	}
	return (first);
}

t_cmd	*mini_parse(char *line)
{
	t_token	*token;
	
	token = tokenize(line);
	while (token != NULL)
	{
		t_token__print(token);
		token = token->next;
	}
	return (NULL);
}
