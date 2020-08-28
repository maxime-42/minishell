/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:36:23 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/28 10:24:05 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	    *ft_strnew(size_t size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * size)))
		return (0);
	ft_bzero(str, size);
	return (str);
}