/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:38:36 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/09 14:07:14 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			error_msg(char *value)
{
	ft_putstr_fd("minishell: erreur de syntaxe près du symbole inattendu « ", 1);
	ft_putchar_fd(value[0], 1);
	ft_putchar_fd(value[1], 1);
	ft_putstr_fd(" »\n", 1);
	g_info.ret = ERROR_BASH;
}

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
		error_msg(token->value);
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
		error_msg(token->value);
		return (ERROR);
	}
	else if (size == 2)
	{
		if (token->type == pipeline)
			token->type = or;
		else if (token->type == semicolon)
			error_msg(token->value);
	}
	else if (size == 1 && token->type == and)
		token->type = literal;
	return (SUCCESS);
}

int					correction_syntaxe_operator(t_token *token)
{
	int				code_err;

	code_err = SUCCESS;
	if (is_operator(token->type) == true)
	{
		if (token->type == and)
			code_err = correction_and_pipeline_semicolon(token);
		else if (token->type == pipeline)
			code_err = correction_and_pipeline_semicolon(token);
		else if (token->type == semicolon)
			code_err = correction_and_pipeline_semicolon(token);
		else if (token->type == simple_redir_right)
			code_err = correction_redirection(token);
		else if (token->type == simple_redir_left)
			code_err = correction_redirection(token);
	}
	return (code_err);
}