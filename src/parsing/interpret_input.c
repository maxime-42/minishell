/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/09 14:33:25 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list		*find_next_literal(t_list *current)
{
	t_token_type	type;

	while (current)
	{
		type = get_token_type(current->content);
		if (type == literal)
			return (current);
		current = current->next;
	}
	return (0);
}

/*
** if i have something like "> 1 2" this function transforme it "1 > 2"
*/
static void				special_case_redirection(t_list *current)
{
	t_list			*next_literal;
	t_list			*after_next_literal;

	next_literal = find_next_literal(current->next);
	after_next_literal = find_next_literal(next_literal->next);
	swap_token(next_literal->content, after_next_literal->content);
	swap_token(current->content, next_literal->content);
}

/*
** check if the first token is not a operator
** example :
**          && ls 
**			|| pwd
**			...
*/
static int			first_token_is_not_operator(t_token *token, int count)
{
	if (!count && is_operator(token->type) == true)
	{
		g_info.ret = ERROR_BASH;
		ft_putstr_fd("minishell: erreur de syntaxe près du symbole inattendu « ", 1);
		ft_putstr_fd(token->value, 1);
		ft_putstr_fd(" »\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

int					iter_list_1(t_list **begin)
{
	t_token			*token;

	while (*begin)
	{
		token = ((*begin)->content);
		if (token->type == single_quote || token->type == double_quote)	
		{
			if (dealt_quote(begin) == ERROR)
				return (ERROR);
		}
		else if (token->type != space)
		{
			interpret_backslashe(begin);
			interpret_variable(begin);
			concate_token_same_type(begin, get_token_type((*begin)->content));
			if (correction_syntaxe_operator((*begin)->content) == ERROR)
				return (ERROR);
			if (is_separator(get_token_type((*begin)->content)) == true)
				return (SUCCESS);
		}
		*begin = (*begin)->next;
	}
	return (SUCCESS);
}

int					iter_list_2(t_list *tmp)
{
	int				count;
	t_token			*token;

	count = 0;
	while (tmp)
	{
		token = tmp->content;
		if (is_separator(token->type))
			return (true);
		if (!count && is_right_side_redirection(token->type) == true)
			special_case_redirection(tmp);
		if (first_token_is_not_operator(token, count) == ERROR)
			return (ERROR);
		if (token->type != space)
			count += 1;
		tmp = tmp->next;
	}
	return (SUCCESS);
}