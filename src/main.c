/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/09 15:08:57 by mkayumba         ###   ########.fr       */
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

void        print_tab(void *ptr)
{
    char    **array;
    
    array = (char **)ptr;
    printf("[%s]\n", array[0]);
}

void        print_str(void *ptr)
{
    char    *array;
    
    array = (char *)ptr;
    printf("%s\n", array);
}

int main(int ac, char **av, char **env)
{
    char    *str_input;
    int     nb_backslash;
    t_list  *tmp;
    t_token *token;
    char    **array;
    
    nb_backslash = 0;
    g_info.root = 0;
    g_info.str_input = 0;
    g_info.list_input = 0;
    g_info.list_env = 0;

    g_info.list_env = init_env(env);
    str_input = promp();
    g_info.str_input = str_input;
    g_info.list_input = transform_input_in_list_token(str_input);
    
    printf("\n_________________avant____________\n");
    ft_lstiter(g_info.list_input, &print_token);

    interpret_backslashe(&g_info.list_input->next);

    printf("\n_________________apres____________\n");
    ft_lstiter(g_info.list_input, &print_token);

    // interpret_backslashe(&g_info.list_input);
    //interprete_variable(&g_info.list_input);
    //delete_space(&g_info.list_input);
    // concate_token_same_type(&g_info.list_input, literal);
    //interpret_variable(&g_info.list_input, g_info.list_env);

  

    //tmp = interprete_backslash(g_info.list_input, &nb_backslash);

    //print_token(token);
    //array = token->value;
    //printf("\n\nagit sur = [%s]\n", array[0]);
    //value = get_value_of_variable_env(g_info.list_env, "PWD=");
    free_all(&g_info, 0);
    // ft_lstclear(&begin, &ft_free_double_array);

    // ft_lstclear(&begin, &ft_free_double_array);
    // g_info.root = expr(input);
    // begin = g_info.generic_ptr;
    // ft_lstiter(begin, &print_token);
    // ft_lstclear(&begin, &clear_token);
    // free(input);
    //t_token *token;
    //root = g_info.root;
   //ft_btree_apply_suffix(g_info.root, &print_token);
    //ft_btree_apply_suffix(g_info.root, &print_token);
    //token = g_info.root->left->left->content;
    //print_tab(token->value);
    //ft_test(g_info.root, &print_token);
    //free_all(&g_info, 0);
    //ft_btree_clear(g_info.root, &clear_token);
    (void)array;
    (void)ac;
    (void)token;
    (void)nb_backslash;
    (void)tmp;
    (void)av;
    (void)env;
    return (0);
}