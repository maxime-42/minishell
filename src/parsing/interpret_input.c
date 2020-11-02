/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:22:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/02 20:47:16 by mkayumba         ###   ########.fr       */
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
** this function check structur of command (cmd)
** i verify after token of type  operator the next one must be token of type literal excepte space
** i ignore token of type space
*/
void				check_structure_cmd(t_token *token, t_info *info)
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

/*
** this let me know if we are inside quote by the flags of quate
*/
static t_bool		is_quote(t_info *info)
{
	unsigned char status;
	
	status = info->status;
	if ((status & (FLAGS_DOUBLE_QUOTE)))
		return (true);
	if ((status & (FLAGS_SINGLE_QUOTE)))
		return (true);
	(void)info;
	return (false);
}

/*
** This function allows interpret every character who needs to be interpreted
** like variables, double quote or simply, backslash and dealt operator
** every character is located in token of linked list 
*/
void				interpret_input(t_list **begin)
{
	t_token_type	type;

	g_info.status = 0;
	while (begin && *begin)
	{
		type = get_token_type((*begin)->content);
		check_quote_open_and_close(type, &g_info);
		if (is_quote(&g_info) == false)
		{
			interpret_backslashe(begin);
			interpret_variable(begin);
			concate_token_same_type(begin, type);
			check_structure_cmd((*begin)->content, &g_info);
			check_syntaxe_operator((*begin)->content);
		}
		if (g_info.ret == ERROR_BASH)
		{
			ft_lstclear(&g_info.list_input, &clear_token);
			return ;
		}
		*begin = (*begin)->next;
	}
}
