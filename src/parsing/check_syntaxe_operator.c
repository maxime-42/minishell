/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:38:36 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/02 20:32:42 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void				error_msg(char *value)
{
	ft_putstr_fd("bash: erreur de syntaxe près du symbole inattendu « ", 1);
	ft_putchar_fd(value[0], 1);
	ft_putchar_fd(value[1], 1);
	ft_putstr_fd(" »\n", 1);
	g_info.ret = ERROR_BASH;
}

static void				correction_redirection(t_token *token)
{
	int				size;

	size = ft_strlen(token->value);
	if (size > 2)
	{
		error_msg(token->value);
	}
	else if (size == 2)
	{
		if (token->type == simple_redir_right)
			token->type = double_redir_right;
	}
}

/*
**	double pipe || become type or
*/
void				correction_and_pipeline_semicolon(t_token *token)
{
	int				size;

	size = ft_strlen(token->value);
	if (size > 2)
		error_msg(token->value);
	else if (size == 2)
	{
		if (token->type == pipeline)
			token->type = or;
		else if (token->type == semicolon)
			error_msg(token->value);
	}
	else if (size == 1 && token->type == and)
		token->type = literal;
}

void				check_syntaxe_operator(t_token *token)
{
	if (is_operator(token->type) == true)
	{
		if (token->type == and)
			correction_and_pipeline_semicolon(token);			
		else if (token->type == pipeline)
			correction_and_pipeline_semicolon(token);
		else if (token->type == semicolon)
			correction_and_pipeline_semicolon(token);
		else if (token->type == simple_redir_right)
			correction_redirection(token);
		else if (token->type == simple_redir_left)
			correction_redirection(token);
	}
}