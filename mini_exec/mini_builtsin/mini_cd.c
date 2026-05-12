/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:04:28 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/12 11:13:59 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "mini_bridge.h"
#include "t_env.h"
#include <unistd.h>

static int	_handle_target(char **args, t_env *m_env_list, \
	char **target_dir, int *print_path)
{
	t_env	*m_found;
	int		arg_i;

	arg_i = 1;
	if (args[arg_i] && ft_strcmp(args[arg_i], "--") == 0)
		arg_i++;
	*target_dir = args[arg_i];
	if (*target_dir && ft_strcmp(*target_dir, "-") == 0)
	{
		m_found = t_env__get_by_key(m_env_list, "OLDPWD");
		if (!m_found || !m_found->m_val)
			return (ft_puterr1(PRE_OUT, "cd: OLDPWD not set\n"), TRUE);
		*target_dir = m_found->m_val;
		*print_path = 1;
	}
	else if (!*target_dir)
	{
		m_found = t_env__get_by_key(m_env_list, "HOME");
		if (!m_found)
			return (TRUE);
		*target_dir = m_found->m_val;
	}
	if (args[arg_i] && args[arg_i + 1])
		return (ft_puterr1(PRE_OUT, "cd: too many arguments\n"), TRUE);
	return (FALSE);
}

static void	_update_pwd(t_env **m_env_list, char *old_pwd_val, int print_path)
{
	char	cwd[4096];
	t_env	*m_found;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (print_path)
			ft_putendl_fd(cwd, 1);
		if (old_pwd_val)
		{
			m_found = t_env__get_by_key(*m_env_list, "OLDPWD");
			if (m_found)
			{
				if (m_found->m_val)
					t_gc__free1(m_found->m_val);
				m_found->m_val = old_pwd_val;
				m_found->val_len = ft_strlen(old_pwd_val);
			}
		}
		m_found = t_env__get_by_key(*m_env_list, "PWD");
		if (m_found)
		{
			m_found->m_val = t_gc__strdup(cwd);
			m_found->val_len = ft_strlen(cwd);
		}
	}
}

int	mini_cd(char **args, t_env **m_env_list)
{
	char	*target_dir;
	char	*old_pwd_val;
	t_env	*m_found;
	int		print_path;

	print_path = 0;
	if (_handle_target(args, *m_env_list, &target_dir, &print_path))
		return (TRUE);
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
	_update_pwd(m_env_list, old_pwd_val, print_path);
	return (FALSE);
}
