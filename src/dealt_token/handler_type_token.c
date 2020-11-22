/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_type_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:50:42 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 21:51:12 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				swap_token(t_token *a, t_token *b)
{
	void			*value_a;
	t_token_type	type_a;

	value_a = a->value;
	type_a = a->type;
	a->value = b->value;
	a->type = b->type;
	b->value = value_a;
	b->type = type_a;
}

t_bool				is_operator(t_token_type type)
{
	if ((type >= 0 && type < NB_OPERATOR))
		return (true);
	return (false);
}

t_bool				is_separator(t_token_type type)
{
	if (type == and || type == or || type == semicolon)
		return (true);
	return (false);
}

void				change_type_of_token(t_list **begin, t_token_type new_type)
{
	t_token			*token;

	if (!begin || !*begin)
		return ;
	token = (*begin)->content;
	if (token->type != new_type)
	{
		token->type = new_type;
	}
}

t_bool				is_right_side_redirection(t_token_type type)
{
	if (type == simple_redir_right || type == double_redir_right)
		return (true);
	return (false);
}
