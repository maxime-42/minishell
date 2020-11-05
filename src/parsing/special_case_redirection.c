/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:35:54 by user42            #+#    #+#             */
/*   Updated: 2020/11/05 13:57:04 by mkayumba         ###   ########.fr       */
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
/*
** if i have something like "> 1 2" this function tranforme it "1 > 2"
*/
void				special_case_redirection(t_list *current)
{
	t_token			*token;
	int				count;
	t_list			*next_literal;
	t_list			*after_next_literal;

	count = 0;
	while (current)
	{
		token = current->content;
		if (count == 0  && is_right_side_redirection(token->type) == true)
		{
			next_literal = find_next_literal(current->next);
			after_next_literal = find_next_literal(next_literal->next);
			swap_token(next_literal->content, after_next_literal->content);
			swap_token(current->content, next_literal->content);
		}
		if (is_operator(token->type) == true)
			count = 0;
		else if (token->type != space)
			count += 1;
		current = current->next;
	}
}