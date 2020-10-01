/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:12:41 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/30 14:12:44 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	get_type_node(t_btree **node)
{
	t_token		*token;

	if (!node || !*node)
		return (eof);
	token = (*node)->content;
	return (token->type);
}