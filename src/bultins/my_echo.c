/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:02:21 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 17:58:32 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_new_line(char **cmd)
{
	int		index;
	int		j;

	index = 0;
	while (cmd[++index])
	{
		j = 0;
		if (cmd[index][j++] == '-')
		{
			while (cmd[index][j] == 'n')
				j++;
			if (cmd[index][j] && cmd[index][j] != 'n')
				return (index);
		}
		else
			return (index);
	}
	return (index);
}

void		my_echo(char **cmd)
{
	int		index;
	t_bool	new_line;

	index = 1;
	new_line = true;
	index = check_new_line(cmd);
	if (index > 1)
		new_line = false;
	while (cmd[index])
	{
		ft_putstr_fd(cmd[index], 1);
		index++;
		if (cmd[index])
			ft_putstr_fd(" ", 1);
	}
	if (new_line == true)
		ft_putstr_fd("\n", 1);
	g_info.ret = SUCCESS;
}
