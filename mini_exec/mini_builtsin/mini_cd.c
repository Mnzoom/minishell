/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:04:28 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/06 13:09:58 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "t_env.h"
#include <unistd.h>

int	mini_cd(char **args, t_env **env_list)
{
	t_env	*m_found;
	char	cwd[4096];
	char	*old_pwd_val;

	if (!args[1])
		return (TRUE);
	if (args[2])
		return (ft_puterr1(PRE_OUT, "cd: too many arguments"), TRUE);
	m_found = t_env__get_by_key(*env_list, "PWD");
	old_pwd_val = m_found->m_val;
	if (chdir(args[1]) != 0)
	{
		ft_puterr1(PRE_OUT, "cd: ");
		perror(args[1]);
		return (TRUE);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (old_pwd_val)
			t_env__get_by_key(*env_list, "OLDPWD")->m_val = old_pwd_val;
		t_env__get_by_key(*env_list, "PWD")->m_val = cwd;
	}
	return (FALSE);
}
