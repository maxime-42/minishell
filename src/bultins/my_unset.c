/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:41:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 13:09:40 by mkayumba         ###   ########.fr       */
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

/*
** verrify syntaxe str, str must have only aphanumeric character
*/

static int		check_name(char *str)
{
	int	i;
	int r;

	i = -1;
	if (!ft_isalpha(str[0]))
		return (ERROR);
	while (str[++i])
	{
		r = ft_isalnum(str[i]);
		if (r == 0)
		{
			return (ERROR);
		}
	}
	return (SUCCESS);
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
		if (check_name(cmd[index]) == ERROR)
			error_(cmd[index]);
		else if ((to_del = ft_list_find(begin, cmd[index], cmp)))
		{
			ft_list_remove_current_node(&begin, to_del, ft_free_string);
			g_info.ret = SUCCESS;
		}
		else
			g_info.ret = SUCCESS;
	}
}
