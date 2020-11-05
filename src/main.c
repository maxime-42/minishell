/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/05 18:00:36 by mkayumba         ###   ########.fr       */
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
	g_info.ret = 0;
	g_info.tab_var_env = 0;
    while (1)
    {
		signal(SIGINT, &handle_signale_ctrl_c);
		// signal(SIGQUIT, &handle_signale_quit);
		promp();
		parsing_input();
		// ft_lstiter(g_info.list_input, &print_token);
		btree_of_cmd(g_info.list_input);
		free_all(&g_info, 0);
    }
	(void)ac;
	(void)av;
	(void)env;
	return (g_info.ret);
}
