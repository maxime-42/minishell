/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:23:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/10 19:39:53 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  t_bool      check_is_variable(t_list **begin)
{
    t_token         *token;

    if (!begin || !*begin)
        return (ERROR);
    token = (*begin)->content;
    if (token->type == variable)
        return (true);
    return (false);
}

void                interpret_variable(t_list **current)
{
    t_token_type    type;
    char            **name;
    t_token         *token;
    char            *value;
    t_list          *to_del;
    
    if (check_is_variable(current) != true)
        return ;
    to_del = *current;
    *current = to_del->next;
    ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
    // printf("test\n");
    print_token((*current)->content);
    // return ;
  
    type = get_type_of_token(current);
    //tmp = (*current)->next;
    concate_token_same_type(current, type);
    // print_token((*current)->content);
    // return ;
    token = (*current)->content;
    name = token->value;
    value = duplique_value_variable(g_info.list_env, name[0]);
    if (value)
    {
        free(name[0]);
        token->type = literal;
        name[0] = value;
    }
}