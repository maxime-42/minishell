/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:52:14 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/02 11:52:41 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_or(t_info *info)
{
	t_token	*token;
	t_list	*to_del;

	if (!info->stack)
		return ;
	to_del = info->stack;
	token = info->stack;		
	dealt_command(token);
	info->stack = to_del->next;
	ft_lstdelone(to_del, free_nothing);
	if (info->ret == ERROR_BASH)
	{
		to_del = info->stack;
		token = info->stack;
		dealt_command(token);
		info->stack = to_del->next;
		ft_lstdelone(to_del, free_nothing);
	}
}