/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:41:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/18 20:14:37 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  void	error_(char *str)
{
	ft_putstr_fd("minishell: unset: `", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("': not a valid identifier\n", 1);
	g_info.ret = ERRR0R_UNSET_VAR;
}

void			my_unset(char **cmd)
{
	t_list	  *to_del;
	int		 index;
	t_list	  *begin;

	index = 0;
	begin = g_info.list_env;
	while (cmd[++index])
	{
		if (ft_strchr(cmd[index], '='))
			error_(cmd[index]);
		else if ((to_del = ft_list_find(begin, cmd[index], cmp)))
		{
			ft_list_remove_current_node(&begin, to_del, ft_free_string);
			g_info.ret = 0;
		}
		else
			error_(cmd[index]);
	}
}