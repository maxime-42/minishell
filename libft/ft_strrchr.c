/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:03:17 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 16:03:36 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	int index_s;

	index_s = (int)ft_strlen(s);
	while (index_s >= 0)
	{
		if (s[index_s] == c)
			return (s + index_s);
		index_s++;
	}
	return (0);
}
