/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/24 17:03:52 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** This function allows interpret every character who needs to be interpreted
** like variables, double quote or simply, backslash and dealt operator
** every character is located in token of linked list 
*/

void				interpret_input(t_list **begin)
{
	t_token_type	type;
	
	while (begin && *begin)
	{
		type = get_token_type((*begin)->content);
		interpret_backslashe(begin);
		if (type  == single_quote || type == double_quote)
			dealt_quote(begin);
		else
		{
			interpret_variable(begin);
			concate_token_same_type(begin, literal);
			handle_operator(begin);
			check_syntax_operator(*begin, type);
		}
		if (*begin)
			*begin = (*begin)->next;
	}
}
