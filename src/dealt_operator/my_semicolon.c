/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_semicolon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:54:49 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/02 14:57:49 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		my_semiconlon(t_info *info)
{
	t_token	*token;
	t_list	*to_del;

	if (!info->stack)
		return ;
	to_del = info->stack;
	token = info->stack->content;		
	dealt_command(token);
	info->stack = to_del->next;
	ft_lstdelone(to_del, free_nothing);
}