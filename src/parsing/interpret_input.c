/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:48:45 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/10 21:08:57 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  t_token_type    get_type_of_quote(t_list **node)
{
    t_token             *token;

    token = (*node)->content;
    if (token->type == single_quote)
    {
        return (single_quote);
    }
    else if (token->type == double_quote)
    {
        return (double_quote);
    }
    return (false);
}

  void      go_to_next(t_list **current)
{
    if (!current || !*current)
        return ;
    while (get_type_of_quote(current) != single_quote)
    {
        change_type_of_token(current, literal);
        *current = (*current)->next;
    }
}

void                interpret_input(t_list **begin)
{
    // t_list  *tmp;

    // tmp = *begin;
    if (!begin || !*begin)
        return ;
    // t_list **tmp;

    // tmp = begin;
    while ((*begin))
    {
        // printf("____________dans la boucle_______\n");
        if (get_type_of_quote(begin) == single_quote)
        {
           ;// go_to_next(begin);
        }
        else
        {
            interpret_backslashe(begin);
            interpret_variable(begin);
            // printf("___________test_______________\n");
            // print_token((*begin)->content);
            
        }
        if (*begin)
            *begin = (*begin)->next;
    }
    // *begin = *tmp;
}