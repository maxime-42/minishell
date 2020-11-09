/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealt_multiples_redirections.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:13:19 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/09 14:53:43 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool		it_is_the_end(t_list *list)
{
	t_token_type	type;

	if (!list)
		return (false);
	type = get_token_type(list->content);
	if (is_operator(type) == true)
	{
		if (is_right_side_redirection(type) == true)
			return (true);
		else
			return (false);
	}
	return (true);
}
/*
** example : 
** 1 > 2 > 3 > 4  become 1 > 2  3  4
*/
void				dealt_multiples_redirections(t_list *list)
{
	t_token			*token;
	int				count;
	t_token_type	save_type;
	
	count = -1;		
	while (it_is_the_end(list) == true)
	{
		token = list->content;
		if (token->type == pipeline)
			count = -1;
		else if (is_right_side_redirection(token->type) == true)
		{
			if (++count && token->type == save_type)
			{
				change_type_of_token(&list, space);
				ft_bzero(token->value, ft_strlen(token->value));
				ft_strcpy(token->value, " ");
			}
			else
				save_type = token->type;
		}
		list = list->next;
	}
}