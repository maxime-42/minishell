/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:04:59 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 21:23:36 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if the variable already exist in the enrinement
*/

int					check_if_var_exist(char *s1, char *s2)
{
	int				size;

	size = 0;
	if (!s2[size])
		return (1);
	while (s1[size] && s1[size] != '=')
	{
		size++;
	}
	size = ft_memcmp(s1, s2, size);
	if (size == 0)
	{
		return (0);
	}
	return (1);
}

static void			modify_existed_variable(t_list *node, char *value)
{
	char			*ptr;
	char			*new_var_env;

	if ((ptr = ft_strchr(node->content, '=')))
		ptr[1] = '\0';
	new_var_env = ft_strjoin(node->content, value);
	ft_free_string(node->content);
	node->content = new_var_env;
}

static void			creat_new_var_env(char *name, char *value)
{
	char			*new_var_env;
	t_list			*node;

	new_var_env = ft_strjoin(name, value);
	node = ft_lstnew(new_var_env);
	if (!node)
	{
		free(new_var_env);
		exit(free_all(&g_info, ERROR));
	}
	ft_lstadd_back(&g_info.list_env, node);
	(void)node;
	(void)new_var_env;
}

void				my_setenv(char *name, char *value)
{
	t_list			*node;

	node = ft_list_find(g_info.list_env, name, &check_if_var_exist);
	if (!node)
	{
		creat_new_var_env(name, value);
	}
	else if (value && ft_strlen(value))
	{
		modify_existed_variable(node, value);
	}
	(void)node;
}
