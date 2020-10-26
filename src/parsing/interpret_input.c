/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/26 17:47:57 by user42           ###   ########.fr       */
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
	
	g_info.status = 0;
	while (begin && *begin)
	{
		
		type = get_token_type((*begin)->content);
		// if (type  == single_quote || type == double_quote)
		// dealt_quote(begin);
		check_quote_open_and_close(type, &g_info);
		if (g_info.status == 0)
		{
			interpret_backslashe(begin);
			interpret_variable(begin);
			concate_token_same_type(begin, literal);
			handle_operator(begin);
			// check_syntax_operator(*begin, type);
		}
		if (*begin)
			*begin = (*begin)->next;
	}
}
