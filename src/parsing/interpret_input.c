/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 15:52:09 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list		*find_next_literal(t_list *current)
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
static void			special_case_redirection(t_list *current)
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
**			&& ls 
**			|| pwd
**			etc
*/
static int			first_token_is_not_operator(t_token *token, int count)
{
	if (!count && is_operator(token->type) == true)
	{
		g_info.ret = ERROR_BASH;
		ft_putstr_fd("minishell: erreur de syntaxe près du symbole inattendu « ", 1);
		ft_putstr_fd(token->value, 1);
		ft_putstr_fd(" »\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

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
		if (!count && is_right_side_redirection(token->type) == true)
			special_case_redirection(tmp);
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

/****************************************************************************/
/*
** 1 > 2  > 3 > 4 become 1 > 2 3 4
*/
static t_token		*multiple_redirection(t_token *token, t_token *save)
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
	printf("wsh\n");
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
 static void		special_case_echo(t_list *list, t_token *token)
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
			special_case_echo(list, token);
			save = multiple_redirection(token, save);
		}
		list = list->next;
	}
	return (SUCCESS);
}