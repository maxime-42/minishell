/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplique_value_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:52:56 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/10 13:58:38 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char        *duplique_value_variable(t_list *list_env, char *variable_name)
{
    char    *value_var;
    char    *duplicate_value;
    
    if (list_env)
    {

        if (!(value_var = get_value_of_variable_env(list_env, variable_name)))
        {
            if (!(duplicate_value = ft_strnew(1)))
                exit(free_all(&g_info, ERROR));
        }
        else
        {
            if (!(duplicate_value = ft_strdup(value_var)))
                exit(free_all(&g_info, ERROR));
        }
        return (duplicate_value);
    }
    return (0);
}