/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel_ast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:06:13 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/30 19:04:41 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** next_token consiste a recupere la commande de l'operateur
** si root n'est pas un operateur on retourne le token de root
** sinon ce le token de la feuille de droite qui est retourner
*/

static t_token		*next_token(t_btree **root)
{
	t_token_type	type;
	t_token			*token;

	type = get_type_node(root);
	if (is_operator(type) != true)
	{
		token = (*root)->content;
	}
	else
	{
		token = (*root)->right->content;
	}
	return (token);
}

/*
** les but de cette fonction consiste de mettre les commandes d'un operateur (type_op) dans la stack
** un operateur a deux fils 
**            les fils left est une commande si seulement si ce pas un operateur
**			  les fils right et toujours une commande
** left child:
** 	dans notre cas dans l'arbre ast les fils left est une commandes seulement si c'etais la premiere commande dans l'input
**
*/

static void			push_cmd_in_stack(t_btree **node, t_token_type type_op)
{
	t_token			*token;
	t_token_type	type;
	t_list			*new;


	g_info.stack = 0;
	type = get_type_node(&(*node)->left);
	if (is_operator(type) != true)
		*node = (*node)->left;
	type = type_op;
	while (type == type_op)
	{
		token = next_token(node);
		if (!(new = ft_lstnew(token)))
			exit(free_all(&g_info, ERROR));
		ft_lstadd_back(&g_info.stack, new);
		*node = get_node_ancestor(*node);
		type = get_type_node(node);
	}
}

/*
** start node : retourne un pointeur surle dernier operateur de l'ast
** si ya pas d'operateur il retouner le node qui a etait passer en parametre
*/

static t_btree		*start_node(t_btree *root)
{
	t_btree			*start;
	t_token			*token;
	t_token_type	type;

	start = root;
	// type = get_type_of_token(start->content);
	token = start->content;
	type = token->type;
	while (is_operator(type) == true)
	{
		token = start->left->content;
		type = token->type;
		if (is_operator(type) != true)
			return (start);
		start = start->left;
	}
	return (start);
}

void				travel_ast(t_btree *root)
{
	t_token			*token;
	t_btree			*start;

	if (!root)
		return ;
	start = start_node(root);
	while (1)
	{
		token = start->content;
		if (is_operator(token->type) == true)
		{
			push_cmd_in_stack(&root, get_type_node(&root));
			dealt_operator(&start);
			return ;
		}
		else
		{
			dealt_command(start->content);
			// start = get_node_ancestor(start);
			return ;
		}
		if (start == (t_btree *)root)
			return ;
	}
}