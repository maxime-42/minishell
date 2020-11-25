/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:38:36 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/25 00:15:05 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** the goal is to change type of token containt >> is to simple redirection
** become double redirection right
*/

static t_bool		correction_redirection(t_token *token)
{
	int				size;

	size = ft_strlen(token->value);
	if (size > 2)
	{
		error_msg("minishell: syntaxe error « ", token->value, "»\n");
		return (false);
	}
	else if (size == 2)
	{
		if (token->type == simple_redir_right)
			token->type = double_redir_right;
	}
	return (true);
}

/*
**	double pipe || become type or
*/

static int			correction_and_pipeline_semicolon(t_token *token)
{
	int				size;

	size = ft_strlen(token->value);
	if (size > 2)
	{
		error_msg("minishell: syntaxe error « ", token->value, "»\n");
		return (ERROR);
	}
	else if (size == 2)
	{
		if (token->type == pipeline)
			token->type = or;
		else if (token->type == semicolon)
			error_msg("minishell: syntaxe error « ", token->value, "»\n");
	}
	else if (size == 1 && token->type == and)
		token->type = literal;
	return (SUCCESS);
}

static void			error_(char *value)
{
	error_msg("minishell: syntaxe error « ", value, "»\n");
	g_info.ret = SYNTAXE_ERROR;
}

/*
** two operator succesif it is an error
** && >> , ; , >; ...
*/

int					check_op(t_list *list, t_token *token)
{
	if (ft_strlen(token->value) > 2)
	{
		error_(token->value);
		return (ERROR);
	}
	list = find_next_literal(list->next);
	if (!list)
	{
		error_(token->value);
		return (ERROR);
	}
	token = list->content;
	if (is_operator(token->type))
	{
		error_(token->value);
		return (ERROR);
	}
	return (SUCCESS);
}

int					correction_syntaxe_operator(t_list *list, t_token *token)
{
	int				code_err;

	code_err = SUCCESS;
	if (is_operator(token->type) == true)
	{
		if (token->type == and)
			code_err = correction_and_pipeline_semicolon(token);
		else if (token->type == pipeline)
			code_err = correction_and_pipeline_semicolon(token);
		else if (token->type == simple_redir_right)
			code_err = correction_redirection(token);
		else if (token->type == simple_redir_left)
			code_err = correction_redirection(token);
		code_err = check_op(list, token);
	}
	return (code_err);
}
