/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type_of_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:42:46 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/09 09:44:07 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void     change_type_of_token(t_list **begin, t_token_type new_type)
{
    t_token     *token;

    token = (*begin)->content;
    if (token->type != new_type)
    {
        token->type = new_type;
    }
}
