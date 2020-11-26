/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealt_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:58:11 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/26 16:41:01 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			handler_last_token(t_list **begin, t_token_type type)
{
	t_list			*to_del;
	t_token			*token;

	token = (*begin)->content;
	if (token->type == type)
	{
		change_type_of_token(begin, literal);
		ft_bzero(token->value, 1);
	}
	else
	{
		to_del = (*begin)->next;
		ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	}
}

/*
** this function interpret everything inside
** double quote => variable and backslash)
*/

static int			iter_list(t_list *tmp, t_token_type type_quote)
{
	t_token			*token;

	while (tmp)
	{
		token = tmp->content;
		if (token->type == type_quote)
			return (SUCCESS);
		if (type_quote == double_quote)
		{
			interpret_backslashe(&tmp, false);
			interpret_variable(&tmp);
		}
		token = tmp->content;
		if (token->type != literal)
			change_type_of_token(&tmp, literal);
		tmp = tmp->next;
	}
	error_msg("minishel : ", "missing quote", "around string\n");
	g_info.ret = SYNTAXE_ERROR;
	return (ERROR);
}

int					dealt_quote(t_list **begin)
{
	t_list			*to_del;
	t_token_type	type_quote;
	int				ret;

	type_quote = get_token_type((*begin)->content);
	to_del = *begin;
	ret = iter_list(to_del->next, type_quote);
	if (ret == ERROR)
	{
		return (ERROR);
	}
	*begin = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	concate_token_same_type(begin, literal);
	handler_last_token(begin, type_quote);
	return (SUCCESS);
}
