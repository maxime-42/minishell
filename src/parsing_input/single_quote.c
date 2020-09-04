/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:16:32 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/04 16:03:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  void    find_close_quote(t_list **open_quote, t_list **close_quote, int *nb)
{
    t_list      *tmp;
    t_token     *token;
    char        **array;
    
    *nb = 0;
    *close_quote = 0;
    tmp = (*open_quote)->next;
    while (tmp)
    {
        token = tmp->content;
        array = (char **)token->value;
        *nb += (int)ft_strlen((char *)tmp->content);
        if (!ft_strcomp(array[0], "'"))
        {
            *close_quote = tmp;
            return ;
        }
        tmp = tmp->next;
    }
    ft_lstclear(&(*open_quote), &clear_token);
    ft_putstr_fd("erreur:\nnot find close quote", 1);
    exit(0);
}

int     size_str(t_list *tmp)
{
    int size_all_content;

    size_all_content = 0;
    while (tmp)
    {
        size_all_content += ft_strlen((char *)tmp->content);
        tmp = tmp->next;
    }
    return (size_all_content);
}

char    *transform_list_in_string(t_list *begin, t_list *end)
{
    char    *str;
    int     size_string;
    t_token *token;
    char    **array;
    t_list  *tmp;

    end->next = 0;
    size_string = size_str(begin);
    if ((str = ft_strnew(size_string + 1)))
        exit (0);
    while (begin)
    {
        token = begin->content;
        array = (char **)token->value;
        ft_strcpy(str, array[0]);
        tmp = begin->next;
        ft_lstdelone(begin, clear_token);
        begin = tmp;
    }
    return (str);
 }

void            empty_line(t_list **begin)
{
    t_token     *token;
    char        **array;

    token = (*begin)->content;
    ft_lstdelone(*begin, &clear_token);
    ft_remove_front(begin, clear_token);
    token = (*begin)->content;
    array = (char **)token->value;
    (void)ft_strcpy(array[0], " ");
}

void            single_quote(t_list **begin)
{
    t_list      *close_quote;
    char        **array;
    char        *str;
    t_token     *token;
    int         nb_character;
    
    nb_character = 0;
    token = (*begin)->content;
    array = (char **)token->value;
    if (!ft_strcmp(array[0], "'"))
    {
        if (!nb_character)
            empty_line(begin);
        else if (nb_character)
        {
            str = transform_list_in_string(*begin, close_quote);
            *begin = close_quote->next;
            token = (*begin)->content;
            array = token->value;
            free(array[0]);
            array[0] = str;
        }
    }
}