/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:00:00 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/28 10:52:17 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_btree_clear(t_btree *root, void (*del)(void *))
{
	if (!root)
		return ;
	if (root->left || root->right)
	{
		ft_btree_clear(root->left, del);
		ft_btree_clear(root->right, del);
	}
	if (root)
	{
		(*del)(root->content);
		root->left = 0;
		root->right = 0;
		free(root);
		root = 0;
	}
}
