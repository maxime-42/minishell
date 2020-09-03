/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:06:52 by lenox             #+#    #+#             */
/*   Updated: 2020/09/03 17:36:51 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	remove_front(t_list **begin_list, void (*free_fct)(void *))
{
	t_list	*prev;

	prev = *begin_list;
	*begin_list = prev->next;
	(*free_fct)(prev->content);
	free(prev);
	prev = 0;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (!begin_list || !*begin_list)
		return ;
	if (!(*cmp)((*begin_list)->content, data_ref))
		remove_front(begin_list, free_fct);
	current = *begin_list;
	while (current)
	{
		if (!(*cmp)(current->content, data_ref))
		{
			tmp = current;
			current = tmp->next;
			(*free_fct)(tmp->content);
			free(tmp);
		}
		else
		{
			current = current->next;
		}
	}
}
