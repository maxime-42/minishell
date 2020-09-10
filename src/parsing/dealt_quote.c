// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   dealt_quote.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/09/03 10:16:32 by mkayumba          #+#    #+#             */
// /*   Updated: 2020/09/10 12:21:33 by mkayumba         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// static  t_list      *get_closing_quote(t_list *open_quote)
// {
//     t_list  *current;
  
//     current = 
//     ft_putstr_fd("erreur:\nnot find close quote", 1);
//     exit(free_all(&g_info, ERROR));
// }

// static  t_bool      is_quote(t_list **begin)
// {
//     t_token         *token;

//     token = (*begin)->content;
//     if (token->type == single_quote)
//         return (true);
//     else if (token->type == double_quote)
//         return (true);
//     return (false);
// }

// static  t_token_type    get_type_quote(t_list **node)
// {
//     t_token *token;

//     token = (*node)->content;
//     if (token->type == single_quote)
//     {
//         return (single_quote);
//     }
//     return (double_quote);
// }

// // static  void    put_everything_in_literal_type(t_list **begin, t_list *quote_close)
// // {
// //     t_list  *current;

// //     current = *begin;
// //     while (current != quote_close)
// //     {
// //         change_type_of_token(&current, literal);
// //         current = current->next;
// //     }
// //     ft_remove_front(begin, &clear_token);
// //     ft_list_remove_current_node(begin, quote_close, &clear_token);
// // }

// void                dealt_quote(t_list **begin)
// {
//     t_token         *token;
//     t_token_type    type_quote;
//     t_list          *quote_close;
//     int             nb_token_between;

//     type_quote = get_type_quote(begin);
//     printf("nb_token_between : [%d]\n", nb_token_between);
//     if (!nb_token_between)
//     {
//         printf("juste un espace\n");
//     }
//     else if (type_quote == single_quote)
//     {
//         printf("simple quote\n");
//     }
//     else if (type_quote == double_quote)
//     {
//         printf("double quote\n");
//     }
// }

// void                quote(t_list **begin)
// {
//     t_list  *current;
//     t_list  quote_closing;

//     if (!*begin || is_quote(begin) == false)
//         return ;
//     quote_closing = get_closig_quote(begin);
//     current = *begin;
//     while (current)
//     {


//     }
    
// }