/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:04:04 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 14:43:19 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void		no_interactive_mode(char *str)
{
	int			i;
	char		*new;
	int			size;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		new = ft_strndup(str + i, 1);
		tokenizer(new);
		ft_strdel(&new);
		i++;
	}
}

int				main(int ac, char **av, char **env)
{
	g_info.list_env = init_env(env);
	g_info.list_path = 0;
	g_info.list_input = 0;
	g_info.ret = 0;
	g_info.tab_var_env = 0;
	if (ac == 3 && !ft_strcmp(av[1], "-c"))
	{
		no_interactive_mode(av[2]);
		btree_of_cmd();
		free_all(&g_info, ERROR);
	}
	else
	{
		while (1)
		{
			signal(SIGINT, &handle_signale_ctrl_c);
			signal(SIGQUIT, SIG_IGN);
			promp();
			btree_of_cmd();
			free_all(&g_info, 0);
		}
	}
	return (g_info.ret);
}
