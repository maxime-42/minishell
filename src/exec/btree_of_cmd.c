/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_of_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:10:55 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/02 16:27:13 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exec_operator(t_list **input_list)
{
	t_token *token;

	if (!*input_list)
		return ;
	token = (*input_list)->content;
	if (is_operator(token->type) == true)
	{
		printf("%s\n", (char *)token->value);

		*input_list = (*input_list)->next;
	}
}

static void			check_quote(t_list *tmp)
{
	t_token_type	type;

	while (tmp)
	{
		type = get_token_type(tmp->content);
		if (is_operator(type) == true)
			return ;
		dealt_quote(&tmp);
		tmp = tmp->next;
	}
}
/*
** ths function prepare a binary for each command  
** example : A B C || E F G && H I J ; K L M  
** in example above we are four  binary  tree 
** the commands is divid by the separotors || , && , ;
**
*/
void		btree_of_cmd(t_list *input)
{
	t_btree	*root;

	while (input)
	{
		root = 0;
		dealt_quote(&input);
		check_quote(input);
		dealt_multiples_redirections(input);
		// ft_lstiter(input, &print_token);
		// ft_lstiter(g_info.list_input, &print_token);
		// exec_operator(&input_list);
		build_ast(&root, &input);
		dealt_exec_cmd(root);
		// ft_btree_dfs_inorder(root, &print_token_tab);
		// print_token_tab(root->right->content);
		ft_btree_clear(root, &btree_free_content);
		// printf("\n");
		// return ;
	}
	(void)root;
}