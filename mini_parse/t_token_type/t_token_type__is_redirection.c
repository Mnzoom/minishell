/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_type__is_redirection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:34:00 by thantoni          #+#    #+#             */
/*   Updated: 2026/03/06 17:35:03 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parse.h"

int	t_token_type__is_redirection(t_token_type t)
{
	return (t == INFILE || t == OVERRIDE || t == APPEND || t == HEREDOC);
}