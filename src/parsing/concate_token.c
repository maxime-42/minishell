/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concate_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:17:57 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/17 18:40:39 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  cette variable concat deux token qui va genere
**  un nouveau token avec avec le type passer en parametre
*/

static t_token	*concate_two_token(t_token *token_1,
				t_token *token_2, t_token_type type)
{
	int			size;
	char		**array_token1;
	char		**array_token2;
	char		*value;
	t_token		*token;

	size = 0;
	array_token1 = token_1->value;
	size = ft_strlen(array_token1[0]);
	array_token2 = token_2->value;
	size += ft_strlen(array_token2[0]);
	if (!(value = ft_strnew(size + 1)))
		return (0);
	ft_strcpy(value, array_token1[0]);
	ft_strcpy(value + ft_strlen(value), array_token2[0]);
	token = create_token(value, type);
	return (token);
}

void			concate_token_same_type(t_list **begin, t_token_type type)
{
	t_token		*new_token;
	t_list		*to_del;

	if (!begin || !*begin || !(*begin)->next)
		return ;
	if (get_token_type((*begin)->content) != type)
		return ;
	if (get_token_type((*begin)->next->content) != type)
		return ;
	if (!(new_token = concate_two_token((*begin)->content,
	(*begin)->next->content, type)))
	{
		exit(free_all(&g_info, ERROR));
	}
	to_del = *begin;
	*begin = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	clear_token((*begin)->content);
	(*begin)->content = new_token;
	concate_token_same_type(begin, type);
}
