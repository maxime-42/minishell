/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_iter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:34:42 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/17 17:51:20 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_array_iter(char **array, void (*fct)())
{
	int index;

	index = 0;
	while (array[index])
	{
		(*fct)(array[index]);
		index++;
	}
}
