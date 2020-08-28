/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_double_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 08:57:45 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/28 10:46:11 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        **ft_copy_double_array(char **dest, char **src)
{
    int     line;

    line = 0;
    while (src[line])
    {
        ft_strcpy(dest[line], src[line]);
        line++;
    }
    return (dest);
}