/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/16 12:19:53 by mkayumba         ###   ########.fr       */
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
    printf("=> [%s]\n\n", array);
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
    // g_info.str_input = promp();
    // parsing_input(g_info.str_input);
        /* free_all(&g_info, 0); */
	/* printf("\n_________________avant____________\n"); */
	/* ft_lstiter(g_info.list_input, &print_token); */

	/* printf("\n_________________apres____________\n"); */
	/* ft_lstiter(g_info.list_input, &print_token); */
    my_setenv("nom de famille", "KAYUMBA");
    printf("_______________environement___________\n");
	ft_lstiter(g_info.list_env, &print_str);

    /* return 0; */
    // g_info.list_input = transform_input_in_list_token(str_input);
    // printf("\n_________________avant____________\n");
    // ft_lstiter(g_info.list_input, &print_token);
    // tmp = g_info.list_input;
    // interpret_input(&tmp);
    // printf("\n_________________apres____________\n");
    // // ft_lstiter(g_info.list_input, &print_token);
    // ft_lstiter(g_info.list_input, &print_token);
    //tmp = interprete_backslash(g_info.list_input, &nb_backslash);
    // printf("___________ast_____________\n");
    // ft_test(g_info.root, &print_token);
      // ft_lstclear(&g_info.list_input, &clear_token);

    free_all(&g_info, 0);
    
    (void)array;
    (void)ac;
    (void)token;
    (void)str_input;
    (void)nb_backslash;
    (void)tmp;
    (void)av;
    (void)env;
    return (0);
}
