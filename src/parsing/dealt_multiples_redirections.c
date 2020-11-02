/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealt_multiples_redirections.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:13:19 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/02 16:19:42 by mkayumba         ###   ########.fr       */
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

void				dealt_multiples_redirections(t_list *list)
{
	t_token			*token;
	int				count;

	count = -1;		
	while (it_is_the_end(list) == true)
	{
		token = list->content;
		if (token->type == pipeline)
			count = 0;
		else if (is_right_side_redirection(token->type) == true)
		{
			if (++count)
			{
				change_type_of_token(&list, space);
				ft_bzero(token->value, ft_strlen(token->value));
				ft_strcpy(token->value, " ");
			}
		}
		list = list->next;
	}
}