/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealt_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:58:11 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/09 13:45:09 by mkayumba         ###   ########.fr       */
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
		*begin = (*begin)->next;
		to_del = *begin;
		*begin = to_del->next;
		ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	}
}

/*
** tous les token qui se trouve entre le quote sont transforme en literal
** the goal is to put every token between quote in  literal type 
*/
static	void			put_in_literal(t_list **begin, t_token_type type_quote)
{
	t_list				*tmp;
	t_token_type		type;

	tmp = *begin;
	while (tmp)
	{
		type = get_token_type(tmp->content);
		if (type == type_quote)
			return ;
		if (type != literal)
		{
			change_type_of_token(&tmp, literal);
		}
		tmp = tmp->next;
	}
}

/*
** this function interpret everything inside double quote => variable and backslash)
*/
static void				if_is_db_quote(t_list **begin, t_token_type type_quote)
{
	t_token_type		type;
	t_list				*tmp;
	int					count;

	count = 0;
	tmp = *begin;
	if (type_quote != double_quote)
		return ;
	while (tmp)
	{
		type = get_token_type(tmp->content);
		if (type == type_quote)
			return ;
		interpret_backslashe(&tmp);
		interpret_variable(&tmp);
		count += 1;
		if (count == 1)
		{
			if (*begin != tmp)
				*begin = tmp;
		}
		tmp = tmp->next;
	}
}
/*
** check if the not missing
*/
int						check_quote_miss(t_list *tmp, t_token_type type)
{
	t_token				*token;
	
	while (tmp)
	{
		token = tmp->content;
		if (token->type == type)
			return (SUCCESS);
		tmp = tmp->next;
	}
	ft_putstr_fd("minishel : missing quote\n", 1);
	g_info.ret = ERROR_BASH;
	return (ERROR);
}

int						dealt_quote(t_list **begin)
{
	t_list				*to_del;
	t_token_type		type;
	
	type = get_token_type((*begin)->content);
	// if (type != single_quote && type != double_quote)
	// 	return (SUCCESS);
	to_del = *begin;
	*begin = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	if (check_quote_miss(*begin, type) == ERROR)
		return (ERROR);
	if_is_db_quote(begin, type);
	put_in_literal(begin, type);
	concate_token_same_type(begin, literal);
	handler_last_token(begin, type);
	return (SUCCESS);
}