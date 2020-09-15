/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_parsing_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:11:35 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/14 15:17:49 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void		init_node(t_btree **node, t_token *token)
{
	if (!(*node = ft_btree_create_node(token)))
	{
		ft_btree_clear(g_info.root, &test_free);
		g_info.root = 0;
		ft_lstclear(&g_info.list_input, &clear_token);
		g_info.list_input = 0;
		exit(free_all(&g_info, ERROR));
	}
}

static	char		**get_new_array(char **array, int nb_col)
{
	int				nb_line_new_array;
	int				nb_column_new_array;
	char			**new_array;

	nb_column_new_array = 0;
	nb_line_new_array = 0;
	ft_get_size_array(array, &nb_line_new_array, &nb_column_new_array);
	nb_line_new_array += 1;
	if (nb_col > nb_column_new_array)
		nb_column_new_array = nb_col;
	new_array = ft_array_char(nb_line_new_array, nb_column_new_array);
	if (!new_array)
		exit(free_all(&g_info, ERROR));
	return (new_array);
}

static	void		update_array(t_btree **root, t_token *new_token)
{
	char			**new_array;
	t_token			*token_root;
	char			**array_root;
	char			**array_new_token;
	int				line;

	token_root = (t_token *)((*root)->content);
	array_root = (char **)token_root->value;
	array_new_token = (char **)new_token->value;
	new_array = get_new_array(array_root, ft_strlen(array_new_token[0]));
	new_array = ft_copy_double_array(new_array, array_root);
	line = ft_nb_line_array(array_root);
	ft_strcpy(new_array[line], array_new_token[0]);
	ft_free_double_array(token_root->value);
	ft_free_double_array(new_token->value);
	free(new_token);
	token_root->value = new_array;
}

void				create_ast(t_btree **root, t_token *token)
{
	t_btree			*node;
	t_token			*root_token;

	node = 0;
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
		root_token = (*root)->content;
		if (is_operator(root_token->type) == true)
		{
			if (!(*root)->right)
				init_node(&(*root)->right, token);
			else
				update_array(&(*root)->right, token);
		}
		else
			update_array(root, token);
	}
}
