/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:07:08 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 19:07:20 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref,
		size_t n, int (*cmp)())
{
	while (begin_list)
	{
		if (!(*cmp)(begin_list->content, data_ref, n))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (begin_list);
}
