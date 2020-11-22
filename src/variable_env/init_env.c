/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:10:02 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 22:50:52 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  cette fonction met les variale environement dans une liste chainée
**  les variable envioronement sont dans la variable 'env'
**  la boucle while consiste a parcourir la variable 'env'
**  chaque iteration dans cette boucle crée
**  un maillot et tous le maillot sont lier
**  a chaque iteration
*/

t_list		*init_env(char **env)
{
	int		index_env;
	t_list	*begin;
	t_list	*new;
	char	*str;

	if (!env || !*env)
		return (0);
	begin = 0;
	index_env = -1;
	while (env[++index_env])
	{
		if (!(str = ft_strdup(env[index_env])))
			exit(free_all(&g_info, ERROR));
		if (!(new = ft_lstnew(str)))
			exit(free_all(&g_info, ERROR));
		ft_lstadd_back(&begin, new);
	}
	return (begin);
}
