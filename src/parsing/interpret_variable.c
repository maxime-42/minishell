/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:23:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/10 13:31:10 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool  check_is_variable(t_list **begin)
{
    t_token *token;

    token = (*begin)->content;

    if (token->type == variable)
        return (true);
    return (false);
}

void        interpret_variable(t_list **current)
{

    if (!*current)
        return ;
    if (check_is_variable(current) == false)
        return ;
    ft_list_remove_current_node(&g_info.list_input, *current, clear_token);
}