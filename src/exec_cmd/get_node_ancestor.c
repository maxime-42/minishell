/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_ancestor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:57:33 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/30 11:10:02 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree				*get_node_ancestor(t_btree *node)
{
	t_btree			*ancestor;

	ancestor = (t_btree *)g_info.root;
	if (node == ancestor)
	{
		return (0);
	}
	while (ancestor && ancestor != node && ancestor->left)
	{
		if (ancestor->left == node)
			return (ancestor);
		ancestor = ancestor->left;
	}
	return (ancestor);
}