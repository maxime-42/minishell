/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:10:02 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/14 10:13:34 by lenox            ###   ########.fr       */
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
	index_env = -1;
	begin = 0;
	while (env[++index_env])
	{
		if (!(str = ft_strdup(env[index_env])))
		{
			ft_putstr_fd("error:\nfailure malloc\n", 1);
			ft_lstclear(&begin, &ft_free_string);
			exit(ERROR);
		}
		if (!(new = ft_lstnew(str)))
		{
			ft_lstclear(&begin, &ft_free_string);
			exit(0);
		}
		ft_lstadd_back(&begin, new);
	}
	return (begin);
}
