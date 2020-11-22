/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:41:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 21:25:24 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2[i])
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((s2[i] == '=' || !s2[i]) ? 0 : 1);
}

static void		error_(char *str)
{
	error_msg("minishell: unset: `", str, "': not a valid identifier\n");
	g_info.ret = ERRR0R_UNSET_VAR;
}

void			my_unset(char **cmd)
{
	t_list		*to_del;
	int			index;
	t_list		*begin;

	index = 0;
	begin = g_info.list_env;
	while (cmd[++index])
	{
		if (ft_strchr(cmd[index], '='))
			error_(cmd[index]);
		else if ((to_del = ft_list_find(begin, cmd[index], cmp)))
		{
			ft_list_remove_current_node(&begin, to_del, ft_free_string);
			g_info.ret = SUCCESS;
		}
		else
			error_(cmd[index]);
	}
}
