/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:46:32 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/27 15:47:13 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
		new->next = *alst;
	else
		new->next = 0;
	*alst = new;
}

void	ft_dlstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *alst;
		(*alst)->prev = new;
	}
	else
		new->next = 0;
	*alst = new;
}
