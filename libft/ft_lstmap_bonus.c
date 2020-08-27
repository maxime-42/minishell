/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:51:24 by mkayumba          #+#    #+#             */
/*   Updated: 2019/11/04 18:51:50 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*tmp;

	if (!lst)
		return (0);
	if (!(tmp = ft_lstnew((*f)(lst->content))))
		return (0);
	begin = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&begin, del);
			return (0);
		}
		tmp = tmp->next;
	}
	return (begin);
}
