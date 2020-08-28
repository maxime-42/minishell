/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:02:51 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/28 18:07:23 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		ft_btree_apply_suffix(root->left, applyf);
		ft_btree_apply_suffix(root->right, applyf);
		(*applyf)(root->content);
	}
}

void	ft_test(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		ft_btree_apply_suffix(root->left, applyf);
		(*applyf)(root->content);
		ft_btree_apply_suffix(root->right, applyf);
	}
}
