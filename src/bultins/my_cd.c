/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:43:57 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/16 18:15:30 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static	void	change_directory(char **cmd)
{
	char		*current_path;
	char		*old_pwd;

	old_pwd = get_value_of_variable_env(g_info.list_env, "PWD");
	current_path = getcwd((char *)NULL, 0);
	if (!cmd[1][0])
	{
		ft_strdel(&cmd[1]);
		cmd[1] = current_path;
	}
	if (chdir(cmd[1]) == ERROR)
	{
		error_msg("minishell: cd: ", cmd[1], strerror(errno));
		ft_putstr_fd("\n", 2);
		g_info.ret = ERROR_BASH;
	}
	else	
		g_info.ret = SUCCESS;
	my_setenv("OLDPWD", old_pwd);
	my_setenv("PWD", current_path);
	free(current_path);
}

void		my_cd(char **cmd)
{
	int		size;
	
	size = ft_nb_line_array(cmd);
	if (size > 2)
	{
		error_msg("minishell: ", "cd: ", "too many argument\n");
		g_info.ret = ERROR_BASH;		
	}
	else
	{
		change_directory(cmd);
	}
}