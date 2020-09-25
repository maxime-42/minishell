/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:49:53 by lenox             #+#    #+#             */
/*   Updated: 2020/09/25 13:51:18 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
	{
		ft_putstr_fd("error:\nmalloc failure\n", 1);
		return (0);
	}
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
