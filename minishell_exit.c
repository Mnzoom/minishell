/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:45:02 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 02:39:01 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	minishell_exit(int status)
{
	t_gc__freeall();
	get_next_line(GNL_WIPE);
	rl_clear_history();
	exit(status);
}
