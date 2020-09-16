/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:04:59 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/16 12:19:35 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int		cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((s1[i] == '=') ? 0 : 1);
}

static	char		*create_new_variable(char *var_name, char *var_value)
{
	char			*new_var_env;
	int				size_var_env;

	size_var_env = (int)ft_strlen(var_name);
	if (var_value != 0)
		size_var_env += (int)ft_strlen(var_value);
	new_var_env = ft_strnew(size_var_env + 2);
	ft_strcpy(new_var_env, var_name);
	size_var_env = ft_strlen(new_var_env);
	if (var_value != 0)
		new_var_env[size_var_env++] = '=';
	if (var_value != 0)
		ft_strcpy(new_var_env + size_var_env, var_value);
	return (new_var_env);
}

void				my_setenv(char *name, char *value)
{
	t_list			*node;
	char			*new_var_env;

	node = ft_list_find(g_info.list_env, name, cmp);
	if (!node)
	{
		new_var_env = create_new_variable(name, value);
		if (!(node = ft_lstnew(new_var_env)))
		{
			free(new_var_env);
			exit(free_all(&g_info, ERROR));
		}
		ft_lstadd_back(&g_info.list_env, node);
	}
	else if (value)
	{
		new_var_env = create_new_variable(name, value);
		free(node->content);
		node->content = new_var_env;
	}
}
