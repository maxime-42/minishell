/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concate_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:17:57 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/05 23:36:53 by mkayumba         ###   ########.fr       */
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
	t_token		*new;
	t_list		*to_del;

	if (!begin || !*begin || !(*begin)->next)
		return ;
	if (get_token_type((*begin)->content) != type)
		return ;
	if (get_token_type((*begin)->next->content) != type)
		return ;
	new = concate_two_token((*begin)->content, (*begin)->next->content, type);
	if (!new)
		exit(free_all(&g_info, ERROR));
	to_del = *begin;
	*begin = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	clear_token((*begin)->content);
	(*begin)->content = new;
	concate_token_same_type(begin, type);
}
