/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:53:00 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/26 18:03:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
** this checkin is for double_quote
** here i check if open quote and close quote it exist
** because if we are open we must have closing other is error 
** step one : if i detect quote i set the bit on one
** step two : the next time i will detect other quote i fix the on zero
*/
void				check_quote_open_and_close(t_token_type type, t_info *info)
{
	if (type == single_quote)
	{
		if (info->status & (FLAGS_SINGLE_QUOTE))
			info->status =  info->status & ~ (FLAGS_SINGLE_QUOTE);
		else
			info->status =  info->status | (FLAGS_SINGLE_QUOTE);
	}
	else if (type == double_quote)
	{
		if ((info->status & FLAGS_DOUBLE_QUOTE))
			info->status =  info->status & ~ (FLAGS_DOUBLE_QUOTE);
		else
			info->status =  info->status | (FLAGS_DOUBLE_QUOTE);
	}
}

/*
** i verify after token of type  operator the next one must be token of type literal excepte space
** i ignore token of type space
*/
void				check_next_token_after_operator(t_token *token, t_info *info)
{
	if (token->type !=  space)
	{
		if (is_operator(token->type) == true)
		{
			if ((info->status & FLAGS_OPERATOR))
			{
				ft_putstr_fd("bash: erreur de syntaxe près du symbole inattendu « ", 1);
				ft_putstr_fd(token->value, 1);
				ft_putstr_fd(" »\n", 1);
				exit(free_all(&g_info, ERROR));
			}
			info->status = info->status | (FLAGS_OPERATOR);
		}
		else if (token->type == literal)
		{
			if ((info->status & FLAGS_OPERATOR))
				info->status =  info->status & ~ (FLAGS_OPERATOR);
		}
	}
}