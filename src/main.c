/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/03 17:13:10 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    print_token(void *ptr)
{
    t_token *token;
    int     i;
    char    **array;

    i = 0;
    token = (t_token *)ptr;
    array = (char **)token->value;
    while (array[i])
    {
        printf("value:[%s]\ttype: [%d]\n", array[i], token->type);
        i++;
    }
    printf("\n");
}


char    *promp()
{
    char    *input;

    get_next_line(0, &input);
    return (input);
}

int main(int ac, char **av, char **env)
{
    t_list *begin;
    char    *input;
    
    input = promp();
    g_info.root = expr(input);
    begin = g_info.generic_ptr;
    ft_lstiter(begin, &print_token);
    ft_lstclear(&begin, &clear_token);
    free(input);
    //ft_lstclear(&begin, &ft_free_string);
    //t_token *token;
    //t_btree *root;
    //t_token *token;
    //root = g_info.root;
   //ft_btree_apply_suffix(g_info.root, &print_token);
    //ft_btree_apply_suffix(g_info.root, &print_token);
    //token = g_info.root->left->left->content;
    //print_tab(token->value);
    //ft_test(g_info.root, &print_token);
    //free_all(&g_info, 0);
    //ft_btree_clear(g_info.root, &clear_token);

    (void)ac;
    (void)av;
    (void)env;
    return (0);
}