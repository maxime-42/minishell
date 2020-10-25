/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:53:00 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/24 17:06:46 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
** this checkin is for double_quote
** here i check if open quote and close quote exist
** because if we are open we must have closing other is error 
*/
void				check_open_and_close_quote(t_list **begin)
{
	t_token			*token;
	int				count;

	count = 0;
	token = (*begin)->content;
	if (token->type != double_quote)
		return ;
	count++;
	*begin = (*begin)->next;
	while (*begin)
	{
		token = (*begin)->content;
		if (token->type == double_quote)
			return ;
		*begin = (*begin)->next;
	}
	ft_putstr_fd("bash: erreur de syntaxe de quote\n", 1);
	exit(free_all(&g_info, 0));
}

/*
** here i verrify after operator the  next token must not another opeator
*/
void				check_syntax_operator(t_list **current, t_token_type type)
{
	t_list			*prev;

	if (is_operator(type) != true)
		return ;
	*current = (*current)->next;
	type = get_token_type((*current)->content);
	while (*current && type == space)
	{
		prev = *current;
		type = get_token_type((*current)->content);
		*current = (*current)->next;
	}
	if (is_operator(type) == true || !*current)
	{
		ft_putstr_fd("bash: erreur de syntaxe près du symbole inattendu « ", 1);
		ft_putstr_fd(get_token_value((*current)->content), 1);
		ft_putstr_fd(" »", 1);
		exit(free_all(&g_info, 0));
	}
	*current = prev;
}