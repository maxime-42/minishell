/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:44:16 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/12 17:46:23 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        ft_get_size_array(char **array, int *line, int *column)
{
    int     i;
    int     j;

    i = 0;
    while (array[i])
    {
        j = (int) ft_strlen(array[i]);
        if (j > *column)
            *column = j;
        i++;
    }
    *line = i;
}