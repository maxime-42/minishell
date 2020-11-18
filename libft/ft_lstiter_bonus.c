/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:50:39 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/11 22:17:01 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

void	ft_list_iteration(t_list *lst, int (*f)())
{
	int	ret;

	while (lst)
	{
		ret = (*f)(&lst);
		if (ret == STOP)
			return ;
		lst = lst->next;
	}
}
