/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:35:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/31 16:07:03 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			btree_init_node(t_btree **node, t_token *token)
{
	*node = ft_btree_create_node(token);
	if (!*node)
	{
		exit(free_all(&g_info, ERROR));
	}
}

static void			btree_insert(t_btree **root, t_token *token)
{
	t_btree			*node;

	node = 0;
	if (!(*root))
		btree_init_node(root, token);
	else if (is_operator(token->type) == true)
	{
		btree_init_node(&node, token);
		node->left = *root;
		*root = node;
	}
	else
		btree_insert(&(*root)->right, token);
	// else
	// {
	// 	btree_init_node(&(*root)->right, token);
	// }
}
/*
** the goal is to put every argument in list
** example ls a b c && ps
** in the example above this function will put "ls a b c" in linked list
** the spaces is ignore
** agument it is type literal
*/
static void			join_arg(t_list **list, t_token *token)
{
	t_list			*new;

	if (token->type != space)
	{
		new = ft_lstnew(token->value);
		if (!new)
			exit(free_all(&g_info, ERROR));
		ft_lstadd_back(list, new);
	}
}
/*
** the idea of this function consist to put all character string of linked list in tab
 **example :
** 		linked list ls->a->b->c 
** 		tab tab[0] = "ls", tab[1] = "a", tab[2]= "b" , tab[3] = "c"
** the function return tab
*/
static char			**split_list_in_tab(t_list *tmp)
{
	int				size_tab;
	char			**tab;
	int				i;

	i = 0;
	size_tab = ft_lstsize(tmp);
	tab = malloc(sizeof(char **) * (size_tab + 1));
	while (tmp)
	{
		tab[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	tab[i] = 0;
	return (tab);
}

void				print_tab(char **tab)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		printf("tab => [%s]\n", tab[i++]);
	}
}
/*
** take token who contains arguments then create node for that token
** eache node contains token 
**  step one    :	join arguments then if the the are operator
**	step two   :	put this arguments in token then create node for this token
**	step three :	create node for operator
*/
void			build_ast(t_btree **root, t_list **input)
{
	t_token		*token;
	void		*ptr;
	t_list		*list;

	list = 0;
	while (*input && is_separator(get_token_type((*input)->content)) == false)
	{
		token = (*input)->content;
		if (is_operator(token->type) == true)
		{
			ptr = split_list_in_tab(list);
			ft_lstclear(&list, free_nothing);
			ptr = (void *)create_token(ptr, literal);
			btree_insert(root, ptr);

			ptr = ft_split(token->value, "");
			ptr = create_token(ptr, token->type);
			btree_insert(root, ptr);
		}
		else
			join_arg(&list, token);
		*input = (*input)->next;
	}
	if (list)
	{
		ptr = split_list_in_tab(list);
		ft_lstclear(&list, free_nothing);
		ptr = create_token(ptr, literal);
		btree_insert(root, ptr);
	}
}