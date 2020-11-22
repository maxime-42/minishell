/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:20:05 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 21:21:20 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

void			my_pwd(char **cmd)
{
	char		*current_path;

	if (ft_nb_line_array(cmd) == 1)
	{
		if (!(current_path = getcwd((char *)NULL, 0)))
		{
			g_info.ret = ERROR_BASH;
		}
		else
		{
			ft_putstr_fd(current_path, 1);
			ft_free_string(current_path);
			g_info.ret = SUCCESS;
		}
	}
	ft_putstr_fd("\n", 1);
}
