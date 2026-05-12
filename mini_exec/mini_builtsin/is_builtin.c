/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:26:23 by thantoni          #+#    #+#             */
/*   Updated: 2026/05/12 05:08:30 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (FALSE);
	if (ft_strcmp(cmd, "echo") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "cd") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "export") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "unset") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "env") == 0)
		return (TRUE);
	if (ft_strcmp(cmd, "exit") == 0)
		return (TRUE);
	return (FALSE);
}
