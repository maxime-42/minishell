/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:43:10 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 13:44:57 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_free_double_array(void *ptr)
{
	int		line;
	char	**array;

	array = (char **)ptr;
	line = 0;
	if (!array)
		return ;
	while (array[line])
	{
		ft_bzero(array[line], ft_strlen(array[line]));
		free(array[line]);
		array[line] = 0;
		line++;
	}
	free(array);
	array = 0;
}
