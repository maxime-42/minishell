/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:56:18 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/13 22:29:02 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void    print_env(void *content)
{
    char		*var_env;

    var_env = (char *)content;
    if (ft_strchr(var_env, '='))
    {
        ft_putstr_fd(var_env, 1);
        ft_putstr_fd("\n", 1);
    }
}

void    my_env(char **cmd)
{
    ft_lstiter(g_info.list_env, print_env);
    (void)cmd;
}