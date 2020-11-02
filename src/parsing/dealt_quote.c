/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealt_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:58:11 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/02 13:18:39 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void			delete_close_quote(t_list **begin, t_token_type type)
{
	t_list				*to_del;

	if (get_token_type((*begin)->content) == type)
	{
		to_del = *begin;
		*begin = to_del->next;
		ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
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
** the goal is to put every token in literal type inside quote
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
	exit(free_all(&g_info, ERROR));
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

void					dealt_quote(t_list **begin)
{
	t_list				*to_del;
	t_token_type		type_quote;

	type_quote = get_token_type((*begin)->content);
	if (type_quote != single_quote && type_quote != double_quote)
		return ;
	to_del = *begin;
	*begin = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	if_is_db_quote(begin, type_quote);
	put_in_literal(begin, type_quote);
	concate_token_same_type(begin, literal);
	delete_close_quote(begin, type_quote);
}