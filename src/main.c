/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/28 18:14:52 by mkayumba         ###   ########.fr       */
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
    printf("type: %d\n", token->type);
    while (array[i])
    {
        printf("%s\n", array[i]);
        i++;
    }
}
void    print_tab(char **array)
{
    int line;

    line = 0;
    while (array[line])
    {
        printf("%s\n", array[line]);
        line++;
    }
    
}

int main(int ac, char **av, char **env)
{
    t_token *token;
    g_info.root = expr(&av[1]);
    //t_btree *root;
    //t_token *token;
    //root = g_info.root;
   //ft_btree_apply_suffix(g_info.root, &print_token);
    //ft_btree_apply_suffix(g_info.root, &print_token);
    token = g_info.root->left->left->content;
    print_tab(token->value);
    //ft_test(g_info.root, &print_token);
    free_all(&g_info, 0);
    //ft_btree_clear(g_info.root, &clear_token);

    (void)ac;
    (void)av;
    (void)token;
    (void)env;
    return (0);
}