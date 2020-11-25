/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_iter_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:13:09 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/25 14:06:57 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** this function return next token and ignore token type space
*/

t_list				*find_next_literal(t_list *current)
{
	t_token_type	type;

	while (current)
	{
		type = get_token_type(current->content);
		if (type != space)
			return (current);
		current = current->next;
	}
	return (0);
}

/*
** check if the first token is not a operator
** example :
**		&& ls
**		|| pwd
**		etc
*/

int					first_token_is_not_operator(t_token *token, int count)
{
	t_bool			bool;

	bool = is_right_side_redirection(token->type);
	if (bool != true && !count && is_operator(token->type) == true)
	{
		g_info.ret = SYNTAXE_ERROR;
		error_msg("minishell: erreur de syntaxe « ", token->value, " »\n");
		return (ERROR);
	}
	return (SUCCESS);
}

/*
** 1 > 2  > 3 > 4 become 1 > 2 3 4
*/

t_token				*multiple_redirection(t_token *token, t_token *save)
{
	t_bool			bool;
	int				size;

	bool = is_right_side_redirection(token->type);
	if (bool == false)
		return (save);
	if (!save)
	{
		return (token);
	}
	size = ft_strlen(save->value);
	ft_memcpy(save->value, " ", size);
	save->type = space;
	swap_token(save, token);
	return (save);
}

/*
** if i have something like "> 1 2" this function transforme it "1 > 2"
*/

t_list				*special_case_echo(t_list *list, t_token *token)
{
	t_bool			bool;
	t_token			*token_2;
	t_list			*next_literal;
	t_list			*after_next_literal;

	bool = is_right_side_redirection(token->type);
	if (bool != true)
		return (list);
	next_literal = find_next_literal(list->next);
	if (next_literal)
		after_next_literal = find_next_literal(next_literal->next);
	if (!after_next_literal)
		return (list);
	token = next_literal->content;
	token_2 = after_next_literal->content;
	if (token->type != literal || token_2->type != literal)
		return (list);
	swap_token(next_literal->content, after_next_literal->content);
	swap_token(list->content, next_literal->content);
	return ((list->prev) ? list->prev : list);
}