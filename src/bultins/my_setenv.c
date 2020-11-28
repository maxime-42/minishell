/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:04:59 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 13:08:40 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			check_two_if_var_exist(char *s1, char *s2)
{
	int				i;
	int				r;

	r = 1;
	i = 0;
	if (!s2[i])
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	r = s1[i] - s2[i];
	if (!r)
		return (r);
	else if (s1[i] == '=' && !s2[i])
		r = 0;
	return (r);
}

int					check_if_var_exist(char *s1, char *s2)
{
	int				i;
	int				r;

	r = 1;
	i = 0;
	if (!s2[i])
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	r = s1[i] - s2[i];
	if (!r)
		return (r);
	else if (s2[i] == '=' && !s1[i])
		r = 0;
	return (r);
}

static void			modify_existed_variable(t_list *node, char *value)
{
	char			*ptr;
	char			*new_var_env;

	if (!ft_strchr(node->content, '='))
	{
		ptr = ft_strjoin(node->content, "=");
		free(node->content);
		node->content = ptr;
	}
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
	int				size_name;

	size_name = ft_strlen(name);
	node = ft_list_find(g_info.list_env, name, &check_if_var_exist);
	if (!node)
	{
		node = ft_list_find(g_info.list_env, name, &check_two_if_var_exist);
		if (!node)
			creat_new_var_env(name, value);
	}
	else if (node && size_name)
	{
		modify_existed_variable(node, value);
	}
}
