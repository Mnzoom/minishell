/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:05:30 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/05 15:01:15 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_exec.h"
#include <unistd.h>
#include <stdio.h>

int	mini_pwd(t_env *env_list)
{
	char	*pwd_value;
	char	cwd[4096];

	pwd_value = t_env__get_val(env_list, "PWD");
	if (pwd_value == NULL)
		return (0);
	if (pwd_value)
	{
		ft_putendl_fd(pwd_value, 1);
		return (0);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_putendl_fd(cwd, 1); 
		return (0);
	}
	perror("pwd");
	return (1);
}
