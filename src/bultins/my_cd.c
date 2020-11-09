/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:43:57 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/09 17:38:47 by mkayumba         ###   ########.fr       */
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
    // ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("Aucun fichier ou dossier de ce type\n", 1);
	// ft_putstr_fd("\n", 1);
	g_info.ret = ERROR_BASH;
}

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
		error_(cmd[1]);
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
	// printf("size tab = %d\n", size);
	if (size > 2)
	{
		ft_putstr_fd("bash: ", 1);
		ft_putstr_fd("cd: ", 1);
		ft_putstr_fd("too many argument\n", 1);
		g_info.ret = ERROR_BASH;		
	}
	else
	{
		change_directory(cmd);
	}
}