#include "minishell.h"
/*
** what i do in this function => push_left_or_right
** The idea is interior node is type operator and exterior node  is type literal
** The root node it always is an operator except if there are not operator in the input
** The first child is always be at left side 
** then the left child is going be obligatorily type operator and child at right  of
*/
t_bool				push_left_or_right(t_btree **root, t_list *list)
{
	t_token_type	type;
	t_bool			bool;

	bool = false;
	if (*root)
		type = get_token_type((*root)->content);
	if (!(*root))
	{
		*root = ft_btree_create_node(list);
		if (!*root)
			exit(free_all(&g_info, ERROR));
		return (true);
	}
	// type = get_token_type((*root)->left->content);
	if (is_operator(type) == true)
		bool = push_left_or_right(&(*root)->left, list);
	if (bool != true && is_operator(type) == true)
		push_left_or_right(&(*root)->right, list);
	(void)type;
	return (bool);
}

/*
**Here I define the begin and the end of a list
**The attribute "next" of node operator is always be null
*/
void			split_list(t_btree **root, t_list **prev,  t_list **begin)
{
	t_list		*save;
	t_list		*next;

	save = (*prev)->next;
	next = save->next;
	save->next = 0;
	(*prev)->next = 0;
	push_left_or_right(root, save);
	push_left_or_right(root, *begin);
	*begin = next;
}

/*
**The idea is to split list on each operator
*/
void			put_input_list_in_btree(t_btree **root, t_list *current)
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
			split_list(root, &prev, &begin);
			current = begin;
		}
		prev = current;
		current = current->next;
	}
	push_left_or_right(root, begin);
}