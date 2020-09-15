/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:26:53 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/15 12:13:56 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** fonction term:
**	 la fonction terme permet de trouver :
**		  -la valeur du token
**		  -le type du token
**	  un token est delimiter par des espaces exemple :
**	  ls -l ici on a deux token ls et -l
**	  chaque appel de cette fonction retourne un token
*/

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

t_token			*term(t_list **begin)
{
	t_token		*token;
	static	int	is_command = 0;

	token = 0;
	is_command += 1;
	delete_space(begin);
	if (begin && *begin)
	{
		token = (t_token *)(*begin)->content;
		if (is_command == 1)
			token->type = command;
		if (is_operator(token->type) == true)
			is_command = 0;
		return (token);
	}
	return (token);
}

void			parsing_input(char *str_input)
{
	t_btree		*root;
	t_token		*token;
	t_list		*input;

	g_info.list_input = transform_input_in_list_token(str_input);
	input = g_info.list_input;
	printf("\n_________________tokenizer____________\n");
	ft_lstiter(g_info.list_input, &print_token);
	interpret_input(&input);
	printf("\n_________________concatenation des token____________\n");
	ft_lstiter(g_info.list_input, &print_token);
	input = g_info.list_input;
	root = 0;
	while (input)
	{
		if ((token = term(&input)))
		{
			create_ast(&root, token);
			g_info.root = root;
		}
		else
			return ;
		input = input->next;
	}
}
