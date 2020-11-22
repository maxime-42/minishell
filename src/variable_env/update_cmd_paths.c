/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cmd_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:33:13 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 22:54:49 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** if paths exist example :
** path=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/snap/bin
** each call of this function it will return string of path like
** call one 	=> path = "/usr/local/bin/"
** call two 	=> path = "/usr/bin:/bin/"
** call three 	=> path = "/usr/local/games/"
** ...
*/

static char		*extract_path(char *value, char **path)
{
	int			size;
	char		*ptr;

	ptr = ft_strchr(value, ':');
	if (ptr)
	{
		size = ptr - value;
		ptr++;
	}
	else
	{
		size = ft_strlen(value);
		ptr = value + size;
	}
	path[0] = ft_strnew(size + 3);
	if (!path[0])
		exit(free_all(&g_info, ERROR));
	ft_memcpy(path[0], value, size);
	path[0][size] = '/';
	return (ptr);
}

/*
** this function creat linked list of path
*/

void			update_cmd_path(t_info *info)
{
	char		*value;
	char		*path;
	t_list		*new;

	if (!info->list_env)
		return ;
	ft_lstclear(&info->list_path, ft_free_string);
	value = get_value_of_variable_env(info->list_env, "PATH");
	if (!value)
		return ;
	while (*value)
	{
		value = extract_path(value, &path);
		if (!(new = ft_lstnew(path)))
		{
			ft_putstr_fd("malloc failure", 1);
			exit(free_all(info, ERROR));
		}
		ft_lstadd_back(&info->list_path, new);
	}
}
