/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:26:53 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/09 16:49:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	delete_space(t_list **begin)
{
	t_list		*to_del;

	if (!begin || !*begin)
		return ;
	while (get_type_of_token(begin) == space)
	{
		to_del = *begin;
		*begin = to_del->next;
		ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	}
}
/*
** this function put the content of node in token then return the token
** the content it is a token
*/
// t_token			*get_token(t_list **begin)
// {
// 	t_token		*token;
// 	 static	int	is_command = 0;

// 	token = 0;
// 	 is_command += 1;
// 	delete_space(begin);
// 	concate_token_same_type(begin, literal);
// 	if (begin && *begin)
// 	{
// 		token = (t_token *)(*begin)->content;
// 		if (is_command == 1)
// 			token->type = command;
// 		if (is_operator(token->type) == true)
// 			is_command = 0;
// 	}
// 	return (token);
// }

/*
**This function returns a pointer on token
**The token is located inside linked list 
**The token, it is located inside linked list
*/
t_token			*get_token(t_list **begin)
{
	t_token		*token;

	token = 0;
	delete_space(begin);
	concate_token_same_type(begin, literal);
	if (begin && *begin)
	{
		token = (t_token *)(*begin)->content;
	}
	return (token);
}
/*
** this function let met create ast 
** i recovery each token inside linked list one by one 
*/

void			parsing_input(char *str_input)
{
	t_btree		*root;
	t_token		*token;
	t_list		*input;
	int			nb_node;

	transform_input_in_list_token(str_input);
	input = g_info.list_input;
	printf("_________tokenizer_________\n");
	ft_lstiter(g_info.list_input, &print_token);
	printf("\n");
	interpret_input(&input);

	input = g_info.list_input;
	printf("_________concatenation_________\n");
	ft_lstiter(g_info.list_input, &print_token);
	printf("\n");
	root = 0;
	nb_node = 0;
	while (input)
	{
		if ((token = get_token(&input)))
		{
			create_ast(&root, token, nb_node);
			g_info.root = root;
		}
		else
			return ;
		nb_node++;
		input = input->next;
	}
}