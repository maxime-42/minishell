/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:48:45 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/10 13:17:51 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  t_token_type    get_type_of_quote(t_list **node)
{
    t_token *token;

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

static  t_list  *go_to_next(t_list **current)
{
    t_list  *next;

    if (!current)
        ;
    next = (*current)->next;
    while (next && get_type_of_quote(next) != single_quote)
    {
        next = next->next;
    }
    (*current) = next;
}

void        interpret_input(t_list **begin)
{
    t_list  *current;

    current = *begin;
    while (current)
    {
        if (get_type_of_quote(&current) == single_quote)
        {
            go_to_next(current);
        }
        else
        {
            interpret_backslashe(&current);
            interpret_variable(&current);
        }
        if (current)
            current = current->next;
    }
}