/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type_of_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:42:46 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/14 09:49:30 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	la fonction change_type_of_token:
**	change le type d'un token en new_type
*/

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
