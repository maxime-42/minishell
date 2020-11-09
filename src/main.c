/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/09 17:08:28 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  si s1 < s2 retour negatif
**  si si s1 > retour positive 
*/
#include "minishell.h"
#include <signal.h>
void			for_the_tester(char *str)
{
	int			i;
	char		*new;
	
	i = 0;
	int size = ft_strlen(str);
	while (i <= size)
	{
		new = ft_strndup(str + i, 1);
		tokenizer(new);
		ft_strdel(&new);
		i++;
	}
}

int             main(int ac, char **av, char **env)
{
    g_info.list_env = init_env(env);
    g_info.list_path = 0;
	g_info.ret = 0;
	g_info.tab_var_env = 0;
	if (ac == 3)
	{
		for_the_tester(av[2]);
		// printf("av[2] == %s\n", av[2]);
		// ft_lstiter(g_info.list_input, &print_token);
		btree_of_cmd(g_info.list_input);
		free_all(&g_info, 0);
	}
	else
	{
		while (1)
		{
			signal(SIGINT, &handle_signale_ctrl_c);
			signal(SIGQUIT, SIG_IGN);
			promp();
			// t_list *tmp = g_info.list_input;
			// iter_list_1(&tmp);
			// tmp = g_info.list_input;
			// iter_list_2(tmp);
			// ft_lstiter(g_info.list_input, &print_token);
			
			// printf("\n\n");
			// ft_lstiter(g_info.list_input, &print_token);
			btree_of_cmd();
			free_all(&g_info, 0);
		}
	}
	(void)ac;
	(void)av;
	(void)env;
	return (g_info.ret);
}
