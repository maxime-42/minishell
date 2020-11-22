/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_iter_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:13:09 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/22 14:42:56 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list				*find_next_literal(t_list *current)
{
	t_token_type	type;

	while (current)
	{
		type = get_token_type(current->content);
		if (type == literal)
			return (current);
		current = current->next;
	}
	return (0);
}

/*
** if i have something like "> 1 2" this function transforme it "1 > 2"
*/

void				special_case_redirection(t_list *current)
{
	t_list			*next_literal;
	t_list			*after_next_literal;

	next_literal = find_next_literal(current->next);
	if (next_literal)
		after_next_literal = find_next_literal(next_literal->next);
	swap_token(next_literal->content, after_next_literal->content);
	swap_token(current->content, next_literal->content);
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
	if (!count && is_operator(token->type) == true)
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
** if i have echo > file_name msg
** it become echo msg > file_name
*/

void				special_case_echo(t_list *list, t_token *token)
{
	int				ret;
	t_bool			bool;

	ret = ft_strcmp("echo", token->value);
	if (ret)
		return ;
	list = skipt_space(list->next);
	if (list)
	{
		token = list->content;
		bool = is_right_side_redirection(token->type);
		if (bool != true)
			return ;
		special_case_redirection(list);
	}
}
