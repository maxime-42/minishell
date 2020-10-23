#include "minishell.h"

/*
** Here I initializer node of a binary tree
** if malloc failure i immediately  exit program
*/ 
static void		init_node(t_btree **node, t_list *list)
{
	*node = ft_btree_create_node(list);
	if (!*node)
	{
		exit(free_all(&g_info, ERROR));
	}
}

/*
** what i do in this function => push_left_or_right
** The idea is interior node is type operator and exterior node  is type literal
** The root node it always is an operator except if there are not operator in the input
** The first child is always be at left side 
** then the left child is going be obligatorily type operator and child at right  of
*/
static void			push_left_or_right(t_btree **root, t_list *list, t_token_type type)
{
	t_btree			*node;
	t_token_type	type_root;
	
	node = 0;
	type_root = get_token_type((*root)->content);
	if (!(*root))
		init_node(root, list);
	else if (type_root == semicolon && type != semicolon)
		push_left_or_right(&(*root)->right, list, type);
	else if (is_operator(type) == true)
	{
		init_node(&node, list);
		node->left = *root;
		*root = node;
	}
	else
	{
		init_node(&(*root)->right, list);
	}
}

/*
**Here I define the begin and the end of a list
**The attribute "next" of node operator is always be null
*/
t_list			split_list(t_btree **root, t_list **prev,  t_list **begin)
{
	t_list		*save;
	t_token		*token;

	if ((*prev)->next)
	{
		save = (*prev)->next;
		(*prev)->next = 0;
		push_left_or_right(root, *begin, literal);
	}
	if (save->next)
	{
		*prev = save->next;
		save->next = 0;
		token = save->content;
		push_left_or_right(root, save, token->type);
	}
}

/*
**The idea is to split list on each operator
*/
void			put_input_in_btree(t_btree **root, t_list *current)
{
	t_token		*token;
	t_list		*prev;
	t_list		*begin;

	begin = current;
	while (current)
	{
		token = current->content;
		if (is_operator(token->type) == true)
		{
			split_list(root, prev, begin);
		}
		prev = current;
		current = current->next;
	}
	push_left_or_right(root, begin, literal);
}