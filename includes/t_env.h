/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:15:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/04/30 18:40:51 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENV_H
# define T_ENV_H

# include <stddef.h>

typedef struct s_env
{
	char			*m_key;
	size_t			key_len;
	char			*m_val;
	size_t			val_len;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

t_env	*t_env__m_new(char *env_var);
void	t_env__free(t_env *env);
void	t_env__free_all(t_env *m_env_list);
void	t_env__print(t_env *m_env);
void	t_env__print_all(t_env *m_env);
t_env	*t_env__get_by_key(t_env *m_env_list, char *key);
t_env	*t_env__get_by_key1(t_env *m_env_list, char *key, size_t key_n_cmp);
t_env	*t_env__extract_by_key(t_env *m_env_list, char *key);
void	t_env__remove_by_key(t_env **m_env_list, char *key);
size_t	t_env__get_size(t_env *m_env_list);
void	t_env__add_back(t_env **m_env_list, t_env *to_add);
void	t_env_update_var(t_env **m_env_list, char *key, char *new_val);
char	*t_env__get_val(t_env *m_env_list, char *key);
char	**t_env__to_array(t_env *m_env_list);

int		env_is_key_valid(char *key);

#endif