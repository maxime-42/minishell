/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:52:02 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/05 12:36:23 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void *content)
{
	t_list	*p;

	if (!(p = malloc(sizeof(t_list))))
	{
        ft_putstr_fd("error:\nmalloc failure\n", 1);
		return (0);
	}
	p->next = 0;
	p->content = content;
	return (p);
}
