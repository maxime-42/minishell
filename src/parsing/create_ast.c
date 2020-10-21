#include "minishell.h"

static void		init_node(t_btree **node, t_token *token)
{
	*node = ft_btree_create_node(token);
	if (!*node)
	{
		exit(free_all(&g_info, ERROR));
	}
}

/*
** what i do in this function => create_ast
** The idea is interior node is type operator and exterior node  is type literal
** The root node it always is an operator except if there are not operator in the input string
** The first child is always be at left side 
** then the left child is going be obligatorily type operator and child at right  of type literal
*/

static void				push_left_or_right(t_btree **root, t_token *token)
{
	t_btree			*node;

	node = 0;
	if (!token)
		return ;
	if (!(*root))
		init_node(root, token);
	else if (is_operator(token->type) == true)
	{
		init_node(&node, token);
		node->left = *root;
		*root = node;
	}
	else
	{
		init_node(&(*root)->right, token);
	}
}

 static t_token				*new_token(char **join, t_token_type type)
{
	t_token			*token;
	char			**tab;

	if (!*join)
		return (0);
	tab = ft_split(*join, " ");
	ft_strdel(join);
	if (!tab)
		exit(free_all(&g_info, ERROR));
	token = malloc(sizeof(t_token));
	if (!token)
	{
		ft_free_double_array(join);
		exit(free_all(&g_info, ERROR));
	}
	token->value = tab;
	token->type = type;
	return (token);
}

char				*join_arg(char *join, char **tab)
{
	char			*tmp;

	if (!join)
	{
		if (!(join = ft_strjoin(tab[0], " ")))
			exit(free_all(&g_info, ERROR));
	}
	else
	{
		if (!(tmp = ft_strjoin(join, tab[0])))
			exit(free_all(&g_info, ERROR));
		ft_strdel(&join);
		if (!(join = ft_strjoin(tmp, " ")))
			exit(free_all(&g_info, ERROR));
		ft_strdel(&tmp);
	}
	return (join);
}

void			create_ast(t_btree **root, t_list *input)
{
	t_token		*token;
	char		*join;

	join = 0;
	if (!input)
		return ;
	while (input)
	{
		token = input->content;
		if (is_operator(token->type) == true)
		{
			token = new_token(&join, literal);
			push_left_or_right(root, token);
			token = input->content;
			join = join_arg(join, token->value);
			token = new_token(&join, token->type);
			push_left_or_right(root, token);
		}
		else if (token->type != space)
			join = join_arg(join, token->value);
		input = input->next;
	}
	token = new_token(&join, token->type);
	push_left_or_right(root, token);
}