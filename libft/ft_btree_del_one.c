/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:04:21 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 16:12:39 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
