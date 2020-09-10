/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concate_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:01:17 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/10 18:14:05 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
** cette variable concat deux token qui va genere un nouveau token avec avec le type passer en parametre
*/
t_token     *concate_two_token(t_token *token_1, t_token *token_2, t_token_type type)
{
    int     size;
    char    **array_token1;
    char    **array_token2;
    char    *value;
    t_token *token;

    size = 0;
    array_token1 = token_1->value;
    size = ft_strlen(array_token1[0]);
    array_token2 = token_2->value;
    size += ft_strlen(array_token2[0]);
    if (!(value = ft_strnew(size + 1)))
        return(0);
    ft_strcpy(value, array_token1[0]);
    ft_strcpy(value + ft_strlen(value), array_token2[0]);
    token = factor(value, type);
    return (token);
}

/*
** cette fonction concatener le token qui est dans  le maillot begin
** avec le token qui ce trouve dans le maillot suivant(next) du maillot begin tant qu'il sont du meme type
*/

// void        concate_token_same_type(t_list **begin, t_token_type type)
// {
//     t_token *token_begin;
//     t_token *token_next;
//     t_token *new_token;
//     t_list  *next_node;

//     if (begin && *begin && (*begin)->next)
//     {
//         next_node = (*begin)->next;
//         token_begin = (*begin)->content;
//         token_next = next_node->content;
//         if (token_begin->type == type && token_next->type == type)
//         {
//             if (!(new_token = concate_two_token(token_begin, token_next, type)))
//                 exit(free_all(&g_info, ERROR));
//             clear_token(token_next);
//             ft_remove_front(begin, &clear_token);
//             (*begin)->content = new_token;
//             concate_token_same_type(&(*begin), type);
//         }
//     }
// }

void        concate_token_same_type(t_list **begin, t_token_type type)
{
    t_token *new_token;
    t_list  *to_del;

    if (!begin || !*begin || !(*begin)->next)
        return ; 
    if (get_type_of_token(begin) != type)
        return ; 
    if (get_type_of_token(&(*begin)->next) != type)
        return ;
    if (!(new_token = concate_two_token((*begin)->content, (*begin)->next->content, type)))
        exit(free_all(&g_info, ERROR));
    to_del = *begin;
    *begin = to_del->next;
    ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
    clear_token((*begin)->content);
    // ft_remove_front(begin, &clear_token);
    (*begin)->content = new_token;
    concate_token_same_type(begin, type);
}