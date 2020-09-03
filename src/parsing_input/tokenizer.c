/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 11:10:21 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/01 14:49:59 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void        clear(t_list **begin)
{
    ft_lstclear(begin, &ft_free_string);
    exit (ERROR);
}

void        transform_input_in_list_token(t_info *info, char *input)
{
    t_list  *begin;
    t_list  *new;
    int     index_input;
    char    *str;
    t_token *token;
    
    begin = 0;
    index_input = -1;
    while (input[++index_input])
    {
        if (!(str = ft_strnew(2)))
            clear(&begin);
        ft_memcpy((void *)str, (void *)(input + index_input), 1);
        if ((token = factor(str, get_type_token(str))))
        {
            ft_lstclear(&begin, &ft_free_string);
            exit(ERROR);
        }
        if (!(new = ft_lstnew(token)))
            clear(&begin);
        ft_lstadd_back(&begin, new);
    }
    info->generic_ptr = (void *)begin;
}