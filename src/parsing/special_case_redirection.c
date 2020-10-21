/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:35:54 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 18:47:27 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list				*find_next_literal(t_list *current)
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

t_list				*new_list(t_list **next)
{
	t_list			*to_del;
	t_list			*list;
	t_list			*new_elem;

	list = 0;
	while (*next && is_operator(get_token_type((*next)->content)) != true)
	{
		to_del = *next;
		*next = to_del->next;
		if (!(new_elem = ft_lstnew(to_del->content)))
			exit(free_all(&g_info, ERROR));
		free(to_del);
		to_del = 0;
		ft_lstadd_back(&list, new_elem);
	}
	return (list);
}

void				push_back(t_list *list, t_list *to_add)
{
	while (list->next)
		list = list->next;
	list->next = to_add;
}
void				move_linked_list(t_list **current, t_list **prev)
{
	t_list			*list;
	t_list			*next_literal;

	next_literal = find_next_literal((*current)->next);
	if (next_literal)
	{
		list = new_list(&next_literal->next);
		push_back(list, *current);
		if (*prev == *current)
			g_info.list_input = list;
		else
			(*prev)->next = list;
	}
}

void				special_case_redirection(t_list *current)
{
	t_token_type	type;
	int				count;
	t_list			*prev;
	// t_list			*list;s
	// t_list			*next_literal;

	count = 0;
	prev = current;
	while (current)
	{
		type = get_token_type(current->content);
		if (count == 0  && (type == simple_redir_right || type == double_redir_right))
		{
			// next_literal = find_next_literal(current->next);
			move_linked_list(&current, &prev);
		}
		if (is_operator(type) == true)
			count = 0;
		else if (type != space)
			count++;
		prev = current;
		current = current->next;
	}
}