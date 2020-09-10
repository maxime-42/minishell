/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 11:21:46 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/06 10:17:33 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
** 
** dans cette fonction je transforme chaque string du double tableau 'env' un double tableau grace a ft_plite
** ensuite je me le double tableau créé par la fonction ft_split dans une liste chainée en faisant des push back
*/
t_list      *init_env(char **env)
{
    int     index_env;
    t_list  *begin;
    t_list  *new;
    char    *str;

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