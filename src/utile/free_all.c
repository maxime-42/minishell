/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:20:17 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/08 13:12:47 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void                test_free(void *ptr)
{
    (void)ptr;
}

void                free_nothing(void *ptr)
{
    (void)ptr;
}

void    clear_token(void *content)
{
   t_token  *token;
   
    token = (t_token *)content;
    if (token->value)
	{
        ft_free_double_array(token->value);
		token->value = 0;
	}
	free(token);
    (void)token;
    (void)content;
}

// int free_all(t_info *info, int code_return)
// {
//     if (info->root)
//         ft_btree_clear(info->root, &clear_token);
//         // ft_btree_clear(info->root, &clear_token);
//     if (info->list_env)
//         ft_lstclear(&info->list_env, &ft_free_string);
//     if (info->str_input)
//         free(info->str_input);
//     if (info->list_input)
//         // ft_lstclear(&info->list_input, &test_free);
//         ft_lstclear(&info->list_input, &clear_token);
//     return (code_return);
// }

int free_all(t_info *info, int code_return)
{
    if (info->root)
    {
        ft_btree_clear(info->root, &clear_token);
        // ft_btree_clear(info->root, &clear_token);
        ft_lstclear(&info->list_input, &free_nothing);
		info->root = 0;
        info->list_input = 0;
    }
    if (info->list_env)
    {
        if (code_return == ERROR)
		{
            ft_lstclear(&info->list_env, &ft_free_string);
			info->list_env = 0;
		}
    }
    if (info->str_input)
        free(info->str_input);
    if (info->list_input)
	{
        ft_lstclear(&info->list_input, &clear_token);
	}
    if (info->list_path)
    {
        ft_lstclear(&info->list_path, ft_free_string);
        info->list_path = 0;
    }
    if (info->tab_var_env)
    {
        free(info->tab_var_env);
        info->tab_var_env = 0;
    }
    if (info->stack)
	{
        ft_lstclear(&info->stack, free_nothing);
		info->stack = 0;
	}
    return (code_return);
}