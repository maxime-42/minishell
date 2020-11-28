/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:20:05 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 14:38:04 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

void			my_pwd(char **cmd)
{
	char		*current_path;

	current_path = getcwd((char *)NULL, 0);
	if (!current_path)
	{
		g_info.ret = ERROR_BASH;
	}
	else
	{
		ft_putstr_fd(current_path, 1);
		ft_free_string(current_path);
		g_info.ret = SUCCESS;
	}
	ft_putstr_fd("\n", 1);
	(void)cmd;
}
