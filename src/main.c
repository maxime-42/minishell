/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/21 09:48:27 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**  si s1 < s2 retour negatif
**  si si s1 > retour positive 
*/
#include "minishell.h"

void	dfs_inorder(t_btree *root)
{
	if (!root)
		return ;
    char    *str;
    str = root->content;
	dfs_inorder(root->left);
	printf("%s ", str);
	dfs_inorder(root->right);
}

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
    printf("[%s]\n", array);
}

int main(int ac, char **av, char **env)
{
    char        *str_input;
    t_list      *tmp;
    t_token     *token;
    char        **array;
    
    g_info.root = 0;
    g_info.str_input = 0;
    g_info.list_input = 0;
    g_info.list_env = 0;

    g_info.list_env = init_env(env);
    g_info.str_input = promp();
    parsing_input(g_info.str_input);
    printf("_________________AST_________________\n");
    ft_test(g_info.root, &print_token);
    token = g_info.root->content;
    my_echo(token->value);
    // my_export(token->value);
    // my_unset(token->value);
    // my_setenv("PWDD=", "KAYUMBA");
    // ft_lstiter(g_info.list_env, print_str);
    // dfs_inorder(node);
    // ft_btree_clear(node, test_free);
    free_all(&g_info, 0);
    (void)array;
    (void)ac;
    (void)token;
    (void)str_input;
    (void)tmp;
    (void)av;
    (void)env;
    return (g_info.ret);
}
