/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/28 14:28:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** This function allows interpret every character who needs to be interpreted
** like variables, double quote or simply, backslash and dealt operator
** every character is located in token of linked list 
*/
void				count_nb_separator(t_token_type type)
{
	if (is_separator(type) == true)
	{
		g_info.size_tab++;
	}		
}

void				interpret_input(t_list **begin)
{
	t_token_type	type;
	
	g_info.status = 0;
	while (begin && *begin)
	{
		type = get_token_type((*begin)->content);
		check_quote_open_and_close(type, &g_info);
		if (!(g_info.status & (FLAGS_DOUBLE_QUOTE)))
		{
			interpret_backslashe(begin);
			interpret_variable(begin);
			concate_token_same_type(begin, type);
			count_nb_separator(type);
			check_token_operator((*begin)->content, &g_info);
		}
		if (*begin)
			*begin = (*begin)->next;
	}
}
