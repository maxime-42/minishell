/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/02 16:26:46 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**  si s1 < s2 retour negatif
**  si si s1 > retour positive 
*/
#include "minishell.h"
#include <signal.h>

t_builtin			g_array_builtin[] = {
	{"echo", my_echo},
	{"cd", my_cd},
	{"pwd", my_pwd},
	{"export", my_export},
	{"unset", my_unset},
	{"env", my_env},
	{"exit", my_exit},
	{0, 0},
};

void            print_string(char *ptr)
{
    printf("[%s]\n", (char*)ptr);
}

int             main(int ac, char **av, char **env)
{
    g_info.list_env = init_env(env);
    g_info.list_path = 0;
    g_info.tab_var_env = 0;
    g_info.stack = 0;
	// t_btree	*node;
    while (1)
    {
        ft_putstr_fd(">", 0);
		signal(SIGINT, &handle_sigint);
        get_next_line(0, &g_info.str_input);
        g_info.root = 0;
        g_info.list_input = 0;
        parsing_input(g_info.str_input);
        update_tab_var_env(g_info.list_env);
        update_cmd_path(&g_info);
		// printf("\n\n___________btree_dfs_inorder____________\n");
        // ft_btree_dfs_inorder(g_info.root, print_token);
		// node = g_info.root;
		// print_token(node->content);
		travel_ast(&g_info, g_info.root);
		// t_btree	*node = g_info.root;
		// dealt_command(node->content);
		// node = g_info.root;
		// while (node->left->left)
		// 	node = node->left;
		// push_cmd_in_stack(&node, get_type_node(&node));
        // ft_lstiter(g_info.stack, &print_token);
         free_all(&g_info, 0);
    //    exit(free_all(&g_info, ERROR));
    }
    (void)ac;
    (void)av;
    (void)env;
    return (g_info.ret);
}
