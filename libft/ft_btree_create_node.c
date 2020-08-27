/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:46:34 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/22 18:57:31 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *content)
{
	t_btree	*node;

	if (!(node = malloc(sizeof(t_btree))))
		return (0);
	node->left = 0;
	node->left = 0;
	node->content = content;
	return (node);
}