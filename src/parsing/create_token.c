/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:24:41 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/09 09:25:24 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token             *create_token(char *token_value, t_token_type token_type)
{
    t_token         *token;
    char            **array;

    if (!(token = malloc(sizeof(t_token))))
        exit(free_all(&g_info, ERROR));
    if (!(token->value = (void *)malloc(sizeof(char *) * (2))))
        return (0);
    array = (char **)token->value;
    array[0] = token_value;
    array[1] = 0;
    token->type = token_type;
    return (token);
}