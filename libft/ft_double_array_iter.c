/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_iter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:03:44 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/17 18:15:02 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_double_array_iter(char **array, void (*fct)(char *))
{
    int index;

    index = 0;
    while (array[index])
    {
        (*fct)(array[index]);
        index++;
    }
}