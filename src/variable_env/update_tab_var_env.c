/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tab_var_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:55:19 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 22:57:53 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		update_tab_var_env(t_list *list_env)
{
	int		nline;

	if (!list_env)
		return ;
	if (g_info.tab_var_env)
	{
		free(g_info.tab_var_env);
		g_info.tab_var_env = 0;
	}
	nline = ft_lstsize(list_env);
	g_info.tab_var_env = malloc(sizeof(char *) * (nline + 1));
	if (!g_info.tab_var_env)
		exit(free_all(&g_info, ERROR));
	nline = -1;
	while (list_env)
	{
		g_info.tab_var_env[++nline] = (char *)list_env->content;
		list_env = list_env->next;
	}
	g_info.tab_var_env[nline] = 0;
}
