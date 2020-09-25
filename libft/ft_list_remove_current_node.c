/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_current_node.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:39:44 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 15:41:32 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void			ft_list_remove_current_node(t_list **begin_list, t_list *to_del,
	void (*free_fct)(void *))
{
	t_list		*tmp;

	if (begin_list && *begin_list)
	{
		if (*begin_list == to_del)
		{
			tmp = (*begin_list);
			(*begin_list) = tmp->next;
			(*free_fct)(tmp->content);
			free(tmp);
			tmp = 0;
			return ;
		}
		else
			ft_list_remove_current_node(&(*begin_list)->next, to_del, free_fct);
	}
}
