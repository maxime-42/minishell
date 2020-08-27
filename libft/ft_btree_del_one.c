/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_one_btree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:04:43 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/22 18:50:08 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_btree_del_one(t_btree *root, void (*del)(void *))
{
	if (root)
	{
		(*del)(root->content);
		root->left = 0;
		root->right = 0;
	}
}