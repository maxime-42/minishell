/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_shlvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:17:51 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/27 23:21:12 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void		incrementer_shelvl(char **cmd)
// {
// 	int		nb;
// 	char	*value;
// 	char	*name;

// 	nb = ft_strcmp("./minishell", cmd[0]);
// 	if (!nb && !cmd[1])
// 	{
// 		value = get_value_of_variable_env(g_info.list_env, "SHLVL");
// 		if (!value || !*value)
// 			return ;
// 		nb = ft_atoi(value);
// 		nb += 1;
// 		value = ft_itoa(nb);
// 		name = ft_strdup("SHLVL=");
// 		printf("nb == [%d] | name = [%s] | value = [%s]\n", nb, name, value);
// 		my_setenv(name, value);
// 		free(value);
// 		free(name);
// 	}	
// }