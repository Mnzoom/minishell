/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:04:28 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/10 09:36:23 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "t_env.h"
#include <unistd.h>

int	mini_cd(char **args, t_env **m_env_list)
{
	t_env	*m_found;
	char	cwd[4096];
	char	*old_pwd_val;
	char	*target_dir;
	int		i;
	int		print_path;

	i = 1;
	print_path = 0;
	if (args[i] && ft_strcmp(args[i], "--") == 0)
		i++;
	target_dir = args[i];
	if (target_dir && ft_strcmp(target_dir, "-") == 0)
	{
		m_found = t_env__get_by_key(*m_env_list, "OLDPWD");
		if (!m_found || !m_found->m_val)
			return (ft_puterr1(PRE_OUT, "cd: OLDPWD not set\n"), TRUE);
		target_dir = m_found->m_val;
		print_path = 1;
	}
	else if (!target_dir)
	{
		m_found = t_env__get_by_key(*m_env_list, "HOME");
		if (m_found)
			target_dir = m_found->m_val;
		else
			return (TRUE);
	}
	if (args[i] && args[i + 1])
		return (ft_puterr1(PRE_OUT, "cd: too many arguments\n"), TRUE);
	m_found = t_env__get_by_key(*m_env_list, "PWD");
	old_pwd_val = NULL;
	if (m_found)
		old_pwd_val = m_found->m_val;
	if (chdir(target_dir) != 0)
	{
		ft_puterr1(PRE_OUT, "cd: ");
		perror(target_dir);
		return (TRUE);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (print_path)
			ft_putendl_fd(cwd, 1);
		if (old_pwd_val)
		{
			m_found = t_env__get_by_key(*m_env_list, "OLDPWD");
			if (m_found)
			{
				m_found->m_val = old_pwd_val;
				m_found->val_len = ft_strlen(old_pwd_val);
			}
		}
		m_found = t_env__get_by_key(*m_env_list, "PWD");
		if (m_found)
		{
			m_found->m_val = ft_strdup(cwd);
			m_found->val_len = ft_strlen(cwd);
		}
	}
	return (FALSE);
}
