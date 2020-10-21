/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/17 18:51:13 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			error_(t_list **current, int nb_print, t_token_type type)
{
	char			**tab;
	t_token			*token;
	int				i;

	i = -1;
	if (type == semicolon)
		nb_print = 2;
	token = (*current)->content;
	tab = token->value;
	ft_putstr_fd("bash: erreur de syntaxe près du symbole inattendu « ", 1);
	while (++i < nb_print)
		ft_putstr_fd(tab[0], 1);
	ft_putstr_fd(" »\n", 1);
	ft_lstclear(&g_info.list_input, &clear_token);
	g_info.list_input = 0;
	*current = 0;
	g_info.ret = ERROR_BASH;
}

static int			count_nb_operator(t_list *current, t_token_type type_op)
{
	int				count;
	t_token			*token;

	count = 0;
	while (current)
	{
		token = current->content;
		if (token->type != type_op)
			return (count);
		count++;
		current = current->next;
	}
	return (count);
}

static void			interpret_operator(t_list **current, t_token_type type_op)
{
	if (type_op == simple_redir_left)
		change_type_of_token(current, double_redir_left);
	else if (type_op == simple_redir_right)
		change_type_of_token(current, double_redir_right);
	else if (type_op == and)
		change_type_of_token(current, and);
	else if (type_op == pipeline)
		change_type_of_token(current, or);
}
/*
** I count numbers of operators if it superior at two so error
** Else i concatenate the next two token
*/
static void			handle_operator(t_list **current)
{
	int				nb_operator;
	t_token_type	type;
	
	if (!current || !*current)
		return ;
	type = get_token_type((*current)->content);
	if (is_operator(type) != true)
		return ;
	nb_operator = count_nb_operator(*current, type);
	if (nb_operator > 2)
		error_(current, (nb_operator / 2), type);
	else if (nb_operator == 1 && type == and)
			change_type_of_token(current, literal);
	else if (nb_operator == 2)
	{
		concate_token_same_type(current, type);
		interpret_operator(current, type);
	}
}
/*
** This function allows interpret every character who needs to be interpreted
** like variables, double quote or simply, backslash and dealt operator
** every character is located in token of linked list 
*/
void				interpret_input(t_list **begin)
{
	t_token_type	type_quote;

	while (begin && *begin)
	{
		type_quote = get_token_type((*begin)->content);
		if (type_quote == single_quote || type_quote == double_quote)
			dealt_quote(begin);
		else
		{
			interpret_backslashe(begin);
			interpret_variable(begin);
			concate_token_same_type(begin, literal);
			handle_operator(begin);
		}
		if (*begin)
			*begin = (*begin)->next;
	}
}
