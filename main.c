/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:14:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/09 07:43:31 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "libft.h" 

int	g_lastsignal = 0;

static void	_handle_line_input(t_line_input *input)
{
	char	*m_line;

	m_line = readline(PRE_IN);
	if (!m_line)
	{
		input->m_lines = NULL;
		printf("exit\n");
		return ;
	}
	if (*m_line)
		add_history(m_line);
	if (input->m_lines)
		ft_freearray(input->m_lines);
	input->m_lines = ft_split(m_line, '\n');
	input->count = 0;
	while (input->m_lines && input->m_lines[input->count])
		input->count++;
	input->current = 0;
	free(m_line);
}

int main(int argc, char **argv, char **envp)
{
	t_env			*m_env_list = NULL;
	t_cmd			*m_cmd_list = NULL;
	t_line_input	input;

	(void)argc, (void)argv;
	input = (t_line_input) { 0 };
	m_env_list = main_cache_envp(envp);
	setup_inputs_signals();
	while (TRUE)
	{
		if (input.current >= input.count)
			_handle_line_input(&input);
		if (!input.m_lines)
			break ;
		if (input.current >= input.count)
			continue ;
		m_cmd_list = mini_parse(input.m_lines[input.current++], m_env_list);
		if (m_cmd_list != NULL)
		{
			g_lastsignal = mini_exec(m_cmd_list, &m_env_list, &input);
			t_cmd__freeall(m_cmd_list);
		}
	}
	return (minishell_exit(EXIT_SUCCESS), EXIT_SUCCESS);
}
