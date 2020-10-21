/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:06:13 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/20 16:32:33 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static t_token		*next_token(t_btree **root)
// {
// 	t_token_type	type;
// 	t_token			*token;

// 	// type = get_type_node(root);
// 	if (*root)
// 		type = eof;
// 	else
// 		type = get_token_type((*root)->content);
// 	if (is_operator(type) != true)
// 	{
// 		token = (*root)->content;
// 	}
// 	else
// 	{
// 		token = (*root)->right->content;
// 	}
// 	return (token);
// }


/*
**The goal of the function it consist to put the left child and right child 
** in stack if they are not operators typing
*/
// static void			push_cmd_in_stack(t_btree **node, t_token_type type_op)
// {
// 	t_token			*token;
// 	t_token_type	type;
// 	t_list			*new;

// 	// type = get_type_node(&(*node)->left);
// 	type = get_token_type((*node)->left->content);
// 	if (is_operator(type) != true)
// 		*node = (*node)->left;
// 	type = type_op;
// 	while (type == type_op)
// 	{
// 		token = next_token(node);
// 		new = ft_lstnew(token);
// 		if (!new)
// 			exit(free_all(&g_info, ERROR));
// 		ft_lstadd_back(&g_info.stack, new);
// 		// print_token((*node)->content);
// 		*node = get_node_ancestor(*node);
// 		if (*node != 0)
// 			type = get_token_type((*node)->content);
// 		else
// 			type = eof;
// 	}
// }

/*
** This function return the last node of type operator in ast
*/
// static t_btree		*start_node(t_btree *root)
// {
// 	t_btree			*start;
// 	t_token			*token;
// 	t_token_type	type;

// 	if (!root)
// 		return (0);
// 	start = root;
// 	token = start->content;
// 	type = token->type;
// 	while (is_operator(type) == true)
// 	{
// 		token = start->left->content;
// 		type = token->type;
// 		if (is_operator(type) != true)
// 			return (start);
// 		start = start->left;
// 	}
// 	return (start);
// }
static void			add_in_stack(t_list **stack, t_token *token)
{
	t_list			*elem;

	if (token)
	{
		elem = ft_lstnew(token);
		if (!elem)
			exit(free_all(&g_info, ERROR));
		ft_lstadd_back(stack, elem);
	}
}

 void			push_cmd_in_stack(t_btree **index, t_list **stack)
{
	t_token_type	tmp_type;
	t_token_type	save_type;

	tmp_type = get_token_type((*index)->content);
	save_type = tmp_type;
	while (save_type == tmp_type)
	{
		printf("hellow\n");
		tmp_type = get_token_type((*index)->left->content);
		if (is_operator(tmp_type) != true)
			add_in_stack(stack, (*index)->left->content);
		// tmp_type = get_token_type((*index)->right->content);
		// if (is_operator(tmp_type) != true)
		add_in_stack(stack, (*index)->right->content);
		*index = get_node_ancestor(*index);
		if (*index)
			tmp_type = get_token_type((*index)->content);
		else
			tmp_type = eof;
	}
}

static t_btree		*get_index(t_btree *root)
{
	t_btree			*index;
	t_btree			*prev;

	index = root;
	prev = index;
	while (index->left)
	{
		prev = index;
		index = index->left;
	}
	return (prev);
}

void				exec_cmd(t_info *info, t_btree *root)
{
	t_btree			*index;
	t_token_type	type;

	// return ;
	if (!root)
		return ;
	index = get_index(root);
	while (index)
	{
		type = get_token_type(index->content);
		if (is_operator(type) == true)
		{
			push_cmd_in_stack(&index, &g_info.stack);
			// printf("\n_______push in stack_____\n");
			// ft_lstiter(g_info.stack, &print_token);
			dealt_operator(type);
			// return ;
			// if (!index)
			// 	printf("index null\n");
			// else
			// 	printf("index pas null\n");
			// printf("\n_______after exec operato in stack_____\n");
			// ft_lstiter(g_info.stack, &print_token);
			// printf("\n");
		}
		else if (is_operator(type) != true)
		{
			// printf("is not operator\n\n");
			dealt_command(index->content);
			index = 0;
		}
		// index = get_node_ancestor(index);
		// else if (info->stack)
		// {
		// 	dealt_command(index->content);
		// }
	}
	(void)info;
}