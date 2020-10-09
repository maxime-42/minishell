/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:06:13 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/08 17:05:44 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
**The goal of the function it consist to put the left child and right child 
** in stack if they are not operators typing
*/
static void			push_cmd_in_stack(t_btree **node, t_token_type type_op)
{
	t_token			*token;
	t_token_type	type;
	t_list			*new;

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
** This function return the last node of type operator in ast
*/
static t_btree		*start_node(t_btree *root)
{
	t_btree			*start;
	t_token			*token;
	t_token_type	type;

	if (!root)
		return (0);
	start = root;
	token = start->content;
	type = token->type;
	while (is_operator(type) == true)
	{
		// if (!start->left)
		// 	printf("left vaut null\n");
		token = start->left->content;
		type = token->type;
		if (is_operator(type) != true)
			return (start);
		start = start->left;
	}
	return (start);
}

void				exec_cmd(t_info *info, t_btree *root)
{
	t_btree			*start;
	t_token_type	type;

	if (!root || !(start = start_node(root)))
		return ;
	return ;
	while (start)
	{
		type = get_type_node(&start);

		if (is_operator(type) == true)
		{
			push_cmd_in_stack(&start, type);
			printf("\n_______push in stack_____\n");
			ft_lstiter(g_info.stack, &print_token);
			printf("\n");
			dealt_operator(type);
			printf("\n_______after exec operato in stack_____\n");
			ft_lstiter(g_info.stack, &print_token);
			printf("\n");
		}
		else if (is_operator(type) != true)
		{
			// printf("is not operator\n\n");
			dealt_command(start->content);
			start = get_node_ancestor(start);
		}
		else if (info->stack)
		{
			dealt_command(start->content);
		}
	}
}