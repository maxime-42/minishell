/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:59:37 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 13:00:29 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_env(void *content)
{
	char		*var_env;

	var_env = (char *)content;
	if (ft_strchr(var_env, '='))
	{
		ft_putstr_fd(var_env, 1);
		ft_putstr_fd("\n", 1);
	}
}

static void		error_(char **cmd)
{
	error_msg("minishell : env: «", cmd[1], "» : No such file or directory\n");
	g_info.ret = ERROR_BASH;
}

void			my_env(char **cmd)
{
	if (!cmd[1])
		ft_lstiter(g_info.list_env, print_env);
	else
	{
		error_(cmd);
	}
	(void)cmd;
}
