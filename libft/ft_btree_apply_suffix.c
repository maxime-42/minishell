/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:15:27 by lenox             #+#    #+#             */
/*   Updated: 2020/09/25 16:15:47 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
