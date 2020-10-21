/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_semicolon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:54:49 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/19 17:52:58 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		my_semiconlon(t_info *info)
{
	t_list	*to_del;
	int		count;

	count = 0;
	if (info->stack)
	{
		while (count < 2)
		{
			dealt_command(info->stack->content);
			to_del = info->stack;
			info->stack = to_del->next;
			ft_lstdelone(to_del, free_nothing);
			count++;
		}
	}
}