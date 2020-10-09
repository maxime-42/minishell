/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/08 15:57:25 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**  si s1 < s2 retour negatif
**  si si s1 > retour positive 
*/
#include "minishell.h"
#include <signal.h>

int             main(int ac, char **av, char **env)
{
    g_info.list_env = init_env(env);
    g_info.list_path = 0;
    g_info.tab_var_env = 0;
    g_info.stack = 0;
	g_info.str_input = 0;
    while (1)
    {
		// signal(SIGINT, &handle_sigint);
        ft_putstr_fd(">", 0);
        get_next_line(0, &g_info.str_input);
		update_tab_var_env(g_info.list_env);
        update_cmd_path(&g_info);
		parsing_input(g_info.str_input);
		printf("\n__________btree_____________________\n");
	    ft_btree_dfs_inorder(g_info.root, print_token);
		exec_cmd(&g_info, g_info.root);
		// exit(free_all(&g_info, ERROR));
        free_all(&g_info, 0);
    }
    (void)ac;
    (void)av;
    (void)env;
    return (g_info.ret);
}
