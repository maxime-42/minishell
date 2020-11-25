/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/25 12:20:55 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					iter_list_1(t_list **begin)
{
	t_token			*token;

	while (*begin)
	{
		token = ((*begin)->content);
		if (token->type == single_quote || token->type == double_quote)
		{
			if (dealt_quote(begin) == ERROR)
				return (ERROR);
		}
		else if (token->type != space)
		{
			interpret_backslashe(begin, true);
			if (interpret_variable(begin) == SUCCESS)
				str_whithout_many_space((*begin)->content);
			concate_token_same_type(begin, get_token_type((*begin)->content));
			if (correction_syntaxe_operator(*begin, (*begin)->content) == ERROR)
				return (ERROR);
			if (is_separator(get_token_type((*begin)->content)) == true)
				return (SUCCESS);
		}
		*begin = (*begin)->next;
	}
	return (SUCCESS);
}

int					iter_list_2(t_list *tmp)
{
	int				count;
	t_token			*token;

	count = 0;
	while (tmp)
	{
		token = tmp->content;
		if (is_separator(token->type))
			return (true);
		if (first_token_is_not_operator(token, count) == ERROR)
			return (ERROR);
		if (token->type != space)
			concate_token_same_type(&tmp, token->type);
		token = tmp->content;
		if (token->type != space)
			count += 1;
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int					iter_list_3(t_list *list)
{
	t_token			*token;
	t_bool			bool;
	t_token			*save;

	save = 0;
	while (list)
	{
		token = list->content;
		bool = is_separator(token->type);
		if (bool == true)
			return (SUCCESS);
		if (token->type != space)
		{
			list = special_case_echo(list, token);
			save = multiple_redirection(list->content, save);
		}
		list = list->next;
	}
	return (SUCCESS);
}
