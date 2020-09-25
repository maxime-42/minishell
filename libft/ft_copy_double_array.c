/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_double_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:58:10 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 14:01:21 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_copy_double_array(char **dest, char **src)
{
	int		line;

	line = 0;
	while (src[line])
	{
		ft_strcpy(dest[line], src[line]);
		line++;
	}
	return (dest);
}
