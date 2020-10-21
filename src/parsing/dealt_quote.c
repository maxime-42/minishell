/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealt_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:58:11 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/17 18:58:36 by mkayumba         ###   ########.fr       */
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
	else if (get_token_type((*begin)->content) == type)
	{
		*begin = (*begin)->next;
		to_del = *begin;
		*begin = to_del->next;
		ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	}
	else
	{
		ft_putstr_fd("error\n: wsh missing are quote close quote\n", 1);
		exit(free_all(&g_info, ERROR));
	}
}

/*
** tous les token qui se trouve entre le quote sont transforme en literal
*/

static	void			change_everything_in_literal_inside_quote
	(t_list **begin, t_token_type type_to_find)
{
	t_list				*tmp;
	t_token_type		type;

	tmp = *begin;
	while (tmp)
	{
		type = get_token_type(tmp->content);
		if (type == type_to_find)
			return ;
		if (type != literal)
		{
			change_type_of_token(&tmp, literal);
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("error:\nmissing are quote close quote\n", 1);
	exit(free_all(&g_info, ERROR));
}

static void				dealt_double_quote
	(t_list **begin, t_token_type type_quote)
{
	t_token_type		type;
	t_list				*tmp;
	int					count;

	count = 0;
	tmp = *begin;
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

	to_del = *begin;
	*begin = to_del->next;
	type_quote = get_token_type(to_del->content);
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	if (!*begin)
	{
		ft_putstr_fd("error:\nclose quote missing\n", 1);
		exit(free_all(&g_info, ERROR));
	}
	if (type_quote == single_quote || type_quote == double_quote)
	{
		if (type_quote == double_quote)
			dealt_double_quote(begin, type_quote);
		change_everything_in_literal_inside_quote(begin, type_quote);
		concate_token_same_type(begin, literal);
		delete_close_quote(begin, type_quote);
	}
}
