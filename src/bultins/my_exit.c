/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:31:13 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/25 14:07:57 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** this function check the arguments of exit function
*/

static int			check_arg(char *arg)
{
	int				nb;
	int				space;

	nb = 0;
	space = 0;
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg)
	{
		if (ft_isdigit(*arg) == 0 && *arg != ' ')
			return (ERROR);
		if (ft_isdigit(*arg) == 1)
			nb = 1;
		if (*arg == ' ' && nb == 1)
			space = 1;
		if (ft_isdigit(*arg) == 1 && space == 1)
			return (ERROR);
		arg++;
	}
	return (SUCCESS);
}

static int			err_(char **cmd)
{
	error_msg("minishell: exit: ", cmd[1], ": numeric argument required\n");
	return (255);
}

void				my_exit(char **cmd)
{
	int				nb;

	nb = g_info.ret;
	if (cmd[1])
	{
		if (check_arg(cmd[1]) == ERROR)
			nb = err_(cmd);
		else
		{
			nb = ft_atoi(cmd[1]);
			nb = nb % 256;
			if (nb <= 0 && ft_strlen(cmd[1]) > 14)
			{
				nb = err_(cmd);
			}
		}
	}
	ft_btree_clear(g_info.ptr, &btree_free_content);
	free_all(&g_info, ERROR);
	exit(nb);
}
