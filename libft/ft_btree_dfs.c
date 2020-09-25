/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_dfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:46:02 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 15:46:50 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_dfs_inorder(t_btree *root, void (*ptr_function)())
{
	if (!root)
		return ;
	ft_btree_dfs_inorder(root->left, ptr_function);
	(*ptr_function)(root->content);
	ft_btree_dfs_inorder(root->right, ptr_function);
}
