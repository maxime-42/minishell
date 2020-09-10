/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_of_variable_env.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:21:54 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/09 10:51:15 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
** 
** le  but de cette fonction est de retourner la valeur d'une variable environement
** sachant qu'il est de la former :  name=value cette fonction va retourne un poiteur sur value 
*/
char        *get_value_of_variable_env(t_list *list_env, char *name)
{
    char    *str_env;
    int     size;

    while (list_env)
    {
        size = ft_strlen(name);
        str_env = (char *)list_env->content;
        if (!ft_memcmp(name, str_env, size))
        {
            if (str_env[size] == '=')
                return (str_env + (size + 1));
        }
        list_env = list_env->next;
    }
    return (0);
}
