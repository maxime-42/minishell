/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:07:39 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 02:08:27 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			print_env(void *content)
{
	char			*str;
	int				i;

	i = -1;
	ft_putstr_fd("declare -x ", 1);
	str = ft_strchr((char *)content, '=');
	if (str)
	{
		str = content;
		while (str[++i] != '=')
			ft_putchar_fd(str[i], 1);
		i++;
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(str + i, 1);
		ft_putstr_fd("\"", 1);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd((char *)content, 1);
		ft_putstr_fd("\n", 1);
	}
	(void)content;
}

static t_list		*sort_var_env(t_list *tmp)
{
	t_list			*sort_list;

	sort_list = 0;
	while (tmp)
	{
		ft_sorted_list_insert(&sort_list, tmp->content, &ft_strcmp);
		tmp = tmp->next;
	}
	return (sort_list);
}

/*
** dans get_name and_value
**on on extrait le nom de la variable et ça valeur dans str
**en suite on passer le nom et la valeur à setenv
**sachant que str peut etre de la forme "nom=value" ou "nom"
**si str est de la forme "nom" value pointe sur basckslash zero
*/

static void			get_name_and_value(char *str)
{
	char			*name;
	char			*value;
	char			*ptr;

	if (check_syntaxe(str) == ERROR)
		return ;
	// printf("wsh\n");
	value = "";
	if ((ptr = ft_strchr(str, '=')))
	{
		name = ft_strndup(str, (ptr - str) + 1);
		value = ft_strndup(ptr + 1, ft_strlen(ptr + 1));
	}
	if (!ptr)
		my_setenv(str, value);
	else
	{
		my_setenv(name, value);
		ft_free_string(name);
		ft_free_string(value);
	}
}

void				my_export(char **cmd)
{
	int				nb_line;
	t_list			*sorted_list;

	nb_line = ft_nb_line_array(cmd);
	// print_tab(cmd);
	if (nb_line == 1)
	{
		sorted_list = sort_var_env(g_info.list_env);
		ft_lstiter(sorted_list, &print_env);
		ft_lstclear(&sorted_list, &free_nothing);
	}
	else
	{
		ft_double_array_iter(cmd + 1, get_name_and_value);
	}
	(void)nb_line;
}
