/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:32:40 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 15:33:57 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_remove_front(t_list **begin, void (*free_fct)(void *))
{
	t_list	*to_free;

	if (begin && *begin)
	{
		to_free = *begin;
		(*begin) = to_free->next;
		(*free_fct)(to_free->content);
		free(to_free);
	}
}
