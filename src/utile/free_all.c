/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:26:22 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 22:28:31 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			free_nothing(void *ptr)
{
	(void)ptr;
}

void			clear_token(void *content)
{
	t_token		*token;

	if (!content)
		return ;
	token = (t_token *)content;
	if (token && token->value)
	{
		ft_memdel(&token->value);
	}
	free(token);
	(void)token;
	(void)content;
}

void			btree_free_content(void *content)
{
	t_token		*token;

	if (!content)
		return ;
	token = (t_token *)content;
	ft_free_double_array(token->value);
	free(token);
	(void)token;
	(void)content;
}

int				free_all(t_info *info, int code_return)
{
	ft_lstclear(&info->list_input, &clear_token);
	info->list_input = 0;
	if (code_return == ERROR)
	{
		ft_lstclear(&info->list_env, &ft_free_string);
		info->list_env = 0;
	}
	ft_lstclear(&info->list_path, ft_free_string);
	info->list_path = 0;
	free(info->tab_var_env);
	info->tab_var_env = 0;
	return (info->ret);
}
