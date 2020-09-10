/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input_in_list_token.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:22:18 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/06 13:36:18 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  int        clear(t_list **begin)
{
        ft_lstclear(begin, &clear_token);
        return (ERROR);
}
/*
** le but et de cette fonction consiste a stranformer un string a un liste de token
** etape 1:
**  dans cette fonction je met chaque charactere de l'input dans une string =>token_value
**etape 2:
**  ensuite je definie le type de cette string 'token_value' avec la fonction get_type
**etape 3:
**  ensuite je crée un token avec les attribue des etapes precedent 1 et 2
**etape 4:
**  puis le token et mis dans un maillot puis un push addback
*/



t_list              *transform_input_in_list_token(char *input)
{
    t_list          *begin;
    t_list          *new;
    int             index_input;
    char            *token_value;
    t_token         *token;
    
    begin = 0;
    index_input = -1;
    while (input[++index_input])
    {
        if (!(token_value = ft_strnew(2)))
            exit(clear(&begin));
        token_value[0] = input[index_input];
        if (!(token = factor(token_value, get_type_token(token_value))))
            exit(clear(&begin));
        if (!(new = ft_lstnew(token)))
            exit(clear(&begin));
        ft_lstadd_back(&begin, new);
    }
    return (begin);
}