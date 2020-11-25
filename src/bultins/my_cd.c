/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:43:57 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/24 16:30:22 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static void			err_(char *go_to_path)
{
	char			*join;
	char			*str_error;

	str_error = strerror(errno);
	join = ft_strjoin(": ", str_error);
	if (!join)
	{
		exit(free_all(&g_info, ERROR));
	}
	error_msg("minishell: cd: ", go_to_path, join);
	ft_putstr_fd("\n", 2);
	ft_strdel(&join);
	g_info.ret = ERROR_CD;
}

static void			change_directory(char *go_to_path)
{
	char			*current_path;
	char			*old_pwd;
	int				ret;

	old_pwd = get_value_of_variable_env(g_info.list_env, "PWD");
	ret = chdir(go_to_path);
	if (ret == ERROR)
	{
		err_(go_to_path);
	}
	else
	{
		current_path = getcwd((char *)NULL, 0);
		my_setenv("OLDPWD", old_pwd);
		my_setenv("PWD", current_path);
		ft_strdel(&current_path);
		g_info.ret = SUCCESS;
	}
}

static char			*path_is_variable(char *path)
{
	char			*go_to;
	
	if (path && path[0] == '-')
		go_to = duplique_value_variable(g_info.list_env, "OLDPWD");
	if (!path || path[0] == '~' || path[0] == '\0' || !go_to)
		go_to = duplique_value_variable(g_info.list_env, "HOME");
	if (!go_to)
	{
		error_msg("minishell: cd: ", "HOME", " not set\n");
	}
	return (go_to);
}

static char			*get_path(char *path)
{
	char			*go_to;

	if (!path || path[0] == '\0' || path[0] == '-' || path[0] == '~')
	{
		go_to = path_is_variable(path);
	}
	else
	{
		go_to = ft_strdup(path);
		if (!go_to)
			exit(free_all(&g_info, ERROR));
	}
	return (go_to);
}

void				my_cd(char **cmd)
{
	int				size;
	char			*got_to;

	size = ft_nb_line_array(cmd);
	if (size > 2)
	{
		error_msg("minishell: ", "cd: ", "too many argument\n");
		g_info.ret = ERROR_CD;
	}
	else
	{
		got_to = get_path(cmd[1]);
		if (got_to)
		{
			change_directory(got_to);
			free(got_to);
		}
	}
}