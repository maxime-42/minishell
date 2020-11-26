/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/26 17:11:11 by mkayumba         ###   ########.fr       */
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
	while (i < size)
	{
		new = ft_strndup(str + i, 1);
		tokenizer(new);
		ft_strdel(&new);
		i++;
	}
}

void    print_env(void *content)
{
    char		*var_env;

    var_env = (char *)content;
    if (ft_strchr(var_env, '='))
    {
        ft_putstr_fd(var_env, 1);
        ft_putstr_fd("\n", 1);
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
		btree_of_cmd();
		free_all(&g_info, ERROR);
		// printf("g_info.ret [%d]\n", g_info.ret);

	}
	else
	{
		// ft_lstiter(g_info.list_env , print_env);
		while (1)
		{
			signal(SIGINT, &handle_signale_ctrl_c);
			signal(SIGQUIT, SIG_IGN);
			promp();
			btree_of_cmd();
			free_all(&g_info, 0);
		}
	}
	(void)ac;
	(void)av;
	(void)env;
	return (g_info.ret);
}
