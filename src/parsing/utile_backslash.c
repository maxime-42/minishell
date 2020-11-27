/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:19:32 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/27 17:27:12 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					count_backslash(t_list *list)
{
	int				count;
	t_token_type	type;

	count = 0;
	while (list)
	{
		type = get_token_type(list->content);
		if (type != backslash)
			return (count);
		count++;
		list = list->next;
	}
	return (count);
}

int					check_last_token(t_list **list)
{
	char			*value;
	t_list			*to_del;

	if (!(*list)->next)
		return (STOP);
	if (get_token_type((*list)->next->content) != literal)
		return (STOP);
	value = get_token_value((*list)->next->content);
	if (value[0] == '$' || value[0] == '"')
	{
		to_del = *list;
		*list = to_del->next;
		ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
		return (STOP);
	}
	return (CONTINUE);
}

/*
** "\\a" this function return pointer on node of "a"
** return pointer after backslash
*/

t_list				*node_after_back_backslash(t_list *list, int nb_backslash)
{
	int				n;

	n = 0;
	// printf("nb_backslash = [%d]\n", nb_backslash);
	while (++n <= nb_backslash)
	{
		list = list->next;
	}
	return (list);
}