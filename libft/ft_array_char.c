/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:08:55 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 19:09:04 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**array_char(int line, int column)
{
	char	**array;
	int		i;

	i = -1;
	if (!(array = malloc(sizeof(char *) * (line + 1))))
		return (0);
	while (++i < line)
	{
		if (!(array[i] = malloc(sizeof(char) * (column + 1))))
		{
			while (++i <= 0)
			{
				free(array[i]);
				array[i] = 0;
			}
			return (0);
		}
		array[i][column] = '\0';
	}
	array[line] = 0;
	return (array);
}
