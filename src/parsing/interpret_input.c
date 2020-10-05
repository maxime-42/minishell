/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/02 17:38:32 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static	void			join_all_close_literal()
// {
// 	t_list				*begin;

// 	begin = g_info.list_input;
// 	while (begin)
// 	{
// 		concate_token_same_type(&begin, literal);
// 		begin = begin->next;
// 	}
// }

void				interpret_input(t_list **begin)
{
	t_token_type	type_quote;

	if (!begin || !*begin)
		return ;
	while ((*begin))
	{
		type_quote = get_type_of_token(begin);
		if (type_quote == single_quote || type_quote == double_quote)
			dealt_quote(begin);
		else
		{
			interpret_backslashe(begin);
			interpret_variable(begin);
			if (get_type_of_token(begin) == literal)
				concate_token_same_type(begin, literal);
		}
		if (*begin)
			*begin = (*begin)->next;
	}
}
