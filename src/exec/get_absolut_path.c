/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolut_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:26:33 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/26 13:59:54 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "minishell.h"
/*
** the is to find path absolut of commande 
** if i have "ls" the path absolut is "/bin/ls"
** for find path absolut
** step one find directory of file 
** step two join name direcatory and the name file "/bin/" "ls"
** step three return the join string
*/

/*
** this function find directory of file "file_to_search"
*/
static char			*find_dir(char *name_dir, char *file_to_search)
{
 	DIR				*folder;
	struct dirent	*entry;

	folder = opendir(name_dir);
	if (!folder)
		return (0);
	while ((entry = readdir(folder)))
	{
		if (!ft_strcmp(entry->d_name, file_to_search))
		{
		// printf("entry->d_name = [%s] | file_to_search = [%s] | name_dir [%s]\n", entry->d_name, file_to_search, name_dir);
			closedir(folder);
			return (name_dir);
		}
	}
	closedir(folder);
	return (0);
}

/*
**this function join name directory and file name
*/
static char			*get_path(char **tab_dir, char *file)
{
	int				index;
	char			*tmp;
	char			*path_absolut;

	index = -1;
	path_absolut = 0;
	while (tab_dir[++index] && path_absolut == NULL)
		path_absolut = find_dir(tab_dir[index], file);
	if (path_absolut)
	{
		tmp = ft_strjoin(path_absolut, "/");
		path_absolut = ft_strjoin(tmp, file);
		free(tmp);
	}
	return (path_absolut);
}

/*
** this function get absolut path of commande
*/

t_bool				get_absolut_path(char **cmd)
{
	char			*value;
	char			**tab_dir;
	char			*path_absolut;

	value = get_value_of_variable_env(g_info.list_env, "PATH");
	if (!value)
	{
		error_msg("minishell: ", cmd[0], ": path is empty\n");
		g_info.ret = ERROR_BASH;
		return (false);
	}
	tab_dir =  ft_split(value, ":");
	if (!tab_dir)
		return (false);
	path_absolut = get_path(tab_dir, cmd[0]);
	// print_tab(tab_dir);
	// printf("cmd = [%s]  path_abs =  [%s]\n", cmd[0], path_absolut);
	if (path_absolut)
	{
		ft_strdel(&cmd[0]);
		cmd[0] = path_absolut;
	}
	ft_free_double_array(tab_dir);
	return ((path_absolut) ? true : false);
}