/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_iter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:34:42 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 15:35:06 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_array_iter(char **array, void (*fct)(char *))
{
	int index;

	index = 0;
	while (array[index])
	{
		(*fct)(array[index]);
		index++;
	}
}
