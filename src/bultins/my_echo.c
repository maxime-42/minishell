/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:12:24 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/31 17:37:00 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_echo(char **cmd)
{
    int	index;
    int	new_line;

    index = 1;
	new_line = 1;
	if (cmd[1])
	{
    	if (!(new_line = ft_strcmp(cmd[1], "-n")))
        	index = 2;
	}
    while (cmd[index])
	{
		ft_putstr_fd(cmd[index], 1);
		index++;
    }
	if (new_line == 2)
		ft_putstr_fd("\n", 1);    
}