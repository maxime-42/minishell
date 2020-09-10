/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:20:17 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/06 13:32:02 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    clear_token(void *content)
{
   t_token  *token;
    token = (t_token *)content;
    ft_free_double_array(token->value);
    free(token);
    (void)token;
    (void)content;
}

int free_all(t_info *info, int code_return)
{
    if (info->root)
        ft_btree_clear(info->root, &clear_token);
    if (info->list_env)
        ft_lstclear(&info->list_env, &ft_free_string);
    if (info->str_input)
        free(info->str_input);
    if (info->list_input)
        ft_lstclear(&info->list_input, &clear_token);
    return (code_return);
}