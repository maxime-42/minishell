/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:46:13 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 13:47:33 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*save;
	t_list	*new;

	if ((*begin_list) && (*cmp)((*begin_list)->content, data) <= 0)
	{
		ft_sorted_list_insert(&(*begin_list)->next, data, cmp);
	}
	else
	{
		new = ft_lstnew(data);
		save = (*begin_list);
		(*begin_list) = new;
		new->next = save;
	}
}
