/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:09:13 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 14:12:08 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_get_size_array(char **array, int *line, int *column)
{
	int		i;
	int		j;

	i = 0;
	while (array[i])
	{
		j = (int)ft_strlen(array[i]);
		if (j > *column)
			*column = j;
		i++;
	}
	*line = i;
}
