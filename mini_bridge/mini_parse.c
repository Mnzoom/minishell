/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:59:40 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/05 18:56:23 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_bridge.h"
#include "mini_parse.h"

t_cmd	*mini_parse(int argc, char **argv)
{
	(void)argc, (void)argv;
	t_cmd	*debug0;
	static char	*debug0_args[] = { "ls", "-l", "-a", NULL };

	
	debug0 = malloc(sizeof(t_cmd));
	debug0->args = debug0_args;
	debug0->infile = NULL;
	debug0->is_append_mode = FALSE;
	debug0->is_heredoc_mode = FALSE;
	debug0->next = NULL;
	debug0->outfile = NULL;
//-----------------------------------------------------
	t_cmd	*debug1;
	static char	*debug1_args[] = { "wc", "--lekaka", "dans les wc", "tu l'as ?", NULL };

	debug1 = malloc(sizeof(t_cmd));
	debug1->args = debug1_args;
	debug1->infile = NULL;
	debug1->is_append_mode = FALSE;
	debug1->is_heredoc_mode = FALSE;
	debug1->next = NULL;
	debug1->outfile = NULL;
	debug0->next = debug1;
	return (debug0);
}
