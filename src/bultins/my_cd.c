/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:43:57 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/24 15:11:35 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static	void	error_(char *path)
{
	ft_putstr_fd("bash: ", 1);
	ft_putstr_fd("cd: ", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(": ", 1);
    ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
	g_info.ret = ERROR_BASH;
}

static	void	change_directory(char *path)
{
	char		*current_path;
	char		*old_pwd;

	old_pwd = get_value_of_variable_env(g_info.list_env, "PWD");
	if (chdir(path) == ERROR)
		error_(path);
	g_info.ret = SUCCESS;
	current_path = getcwd((char *)NULL, 0);
	my_setenv("OLDPWD", old_pwd);
	my_setenv("PWD", current_path);
}

void		my_cd(char **cmd)
{
	int		size;
	
	size = ft_nb_line_array(cmd);
	if (size == 2)
	{
		change_directory(cmd[1]);
	}
	else
	{
		ft_putstr_fd("bash: ", 1);
		ft_putstr_fd("cd: ", 1);
		ft_putstr_fd("too many argument\n", 1);
		g_info.ret = ERROR_BASH;
	}
}