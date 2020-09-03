/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:16:32 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/03 16:00:13 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  void    find_close_quote(t_list **open_quote, t_list **close_quote, int *nb)
{
    t_list  *tmp;

    *nb = 0;
    tmp = *open_quote;
    while (tmp)
    {
        *nb += (int)ft_strlen((char *)tmp->content);
        tmp = tmp->next;
    }
    *close_quote = tmp;
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
void            single_quote(t_list **begin)
{
    t_list      *open_quote;
    t_list      *close_quote;
    char        **array;
    char        *str;
    t_token     *token;
    int         nb_character;
    
    token = (*begin)->content;
    array = (char **)token->value;
    if (!ft_strcmp(array[0], "'"))
    {
        if (!nb_character)
        {
            ft_lstdelone(*begin, &clear_token);
            token = close_quote->content;
            (void)ft_strcpy(array[0], " ");
            *begin = close_quote;
        }
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