/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:35:54 by user42            #+#    #+#             */
/*   Updated: 2020/10/09 17:37:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool				is_redirection_right(t_token_type type)
{
	if ((type == simple_redir_right) || (type == double_redir_right))
		return (true);
	return (false);
}

/*
**put the third element in the first position
*/
void				third_element_in_the_first_position(t_list **first)
{
	t_list			*third_element;
	t_list			*second_element;

	if ((*first)->next && (*first)->next->next)
	{
		second_element = (*first)->next;
		third_element = (*first)->next->next;
		second_element->next = third_element->next;
		third_element->next = *first;
		*first = third_element;
	}
}

/*
**this function swap the third element whit the first
*/
static void			speacial_case_redirection(t_list **current, int n)
{
	t_token_type	type;
	t_token_type	next_type;

	if (!current || !*current)
		return (false);
	type = get_type_of_token(current);
	next_type = get_type_of_token((*current)->next);
	if (is_redirection_right(type) != true)
		return ;
	if (n == 0 && is_redirection_right(type))
	{
		third_element_in_the_first_position(current);
	}
	else if (is_operator(type) && is_redirection_right(next_type) == true)
	{
		third_element_in_the_first_position(current);
	}
}
