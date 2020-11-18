/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concate_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:17:57 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/13 14:38:13 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  cette variable concat deux token qui va genere
**  un nouveau token avec avec le type passer en parametre
*/

static t_token	*concate_two_token(t_token *token_1, t_token *token_2, t_token_type type)
{
	char		*str_token1;
	char		*str_token2;
	char		*join;
	t_token		*token;

	str_token1 = token_1->value;
	str_token2 = token_2->value;
	join = ft_strjoin(str_token1, str_token2);
	if (!join)
		exit(free_all(&g_info, ERROR));
	token = create_token(join, type);
	return (token);
}

/*
** this function join all next closeness token who have the same type
*/
void			concate_token_same_type(t_list **begin, t_token_type type)
{
	t_token		*tmp;
	t_list		*to_del;
	
	while (begin && *begin && (*begin)->next)
	{
		if (get_token_type((*begin)->content) != type)
			return ;
		if (get_token_type((*begin)->next->content) != type)
			return ;
		tmp = (*begin)->next->content;
		tmp = concate_two_token((*begin)->content, tmp, type);
		to_del = *begin;
		*begin = to_del->next;
		clear_token((*begin)->content);
		(*begin)->content = tmp;
		ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	}
}