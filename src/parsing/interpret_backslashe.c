/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_backslashe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:59:40 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 13:49:21 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					put_to_literal(t_list **list)
{
	t_token_type	type;

	type = get_token_type((*list)->content);
	if (type != backslash)
		return (STOP);
	change_type_of_token(list, literal);
	return (CONTINUE);
}

int					del_useless_backslash(t_list **list)
{
	t_token_type	type;
	t_list			*to_del;
	char			*value;

	type = get_token_type((*list)->content);
	if (type != backslash || !(*list)->next)
		return (0);
	value = get_token_value((*list)->next->content);
	if (value[0] == '\\')
	{
		to_del = (*list)->next;
		ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	}
	else
		return (STOP);
	return (CONTINUE);
}

/*
** off backslash meaning put it in literal type
** \\the second token will become token literal type
*/

int					off_backslash(t_list **list)
{
	t_token_type	type;

	type = get_token_type((*list)->content);
	if (type == backslash && (*list)->next)
	{
		change_type_of_token(&(*list)->next, literal);
	}
	return (CONTINUE);
}

/*
** check if backslassh is inside quote or outside
** if we are outside quote and the are one backslash
** this backslash will be delete
*/

t_bool				where_is_backslash(t_list **list, int nb, t_bool in_quote)
{
	char			*value;
	t_list			*to_del;

	if (nb != 1)
		return (false);
	if (in_quote == false)
		return (false);
	if (!(*list)->next)
		return (false);
	value = get_token_value((*list)->next->content);
	if (value[0] == '\\')
		return (false);
	to_del = *list;
	*list = to_del->prev;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	return (true);
}

/*
** if in_quote == true we are ouside quate
** else if in_quote == false we are in quote
*/

int					interpret_backslashe(t_list **list, t_bool in_quote)
{
	t_token_type	type;
	t_list			*next;
	t_bool			bool;
	int				nb_backslash;
	t_list			*tmp;

	type = get_token_type((*list)->content);
	if (type != backslash)
		return (SUCCESS);
	*list = (*list)->prev;
	next = (*list)->next;
	nb_backslash = count_backslash(next);
	tmp = node_after_back_backslash(next, nb_backslash);
	if (in_quote == true && (nb_backslash % 2) && !tmp)
	{
		err_backslash();
		return (ERROR);
	}
	ft_list_iteration(next, &off_backslash);
	ft_list_iteration(next, &del_useless_backslash);
	ft_list_iteration(next, &put_to_literal);
	bool = where_is_backslash(&next, nb_backslash, in_quote);
	if (bool == false)
		ft_list_iteration(next, &check_last_token);
	return (SUCCESS);
}
