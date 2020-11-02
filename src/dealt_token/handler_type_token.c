/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_type_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:01:08 by user42            #+#    #+#             */
/*   Updated: 2020/11/02 15:01:26 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		is_operator(t_token_type type)
{
	if ((type >= 0 && type < NB_OPERATOR))
		return (true);
	return (false);
}

t_bool		is_separator(t_token_type type)
{
	if (type == and || type == or || type == semicolon)
		return (true);
	return (false);
}

void			change_type_of_token(t_list **begin, t_token_type new_type)
{
	t_token		*token;

	if (!begin || !*begin)
		return ;
	token = (*begin)->content;
	if (token->type != new_type)
	{
		token->type = new_type;
	}
}

t_bool		is_right_side_redirection(t_token_type type)
{
	if (type == simple_redir_right || type == double_redir_right)
		return (true);
	return (false);
}