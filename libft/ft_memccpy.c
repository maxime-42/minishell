/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:43:21 by mkayumba          #+#    #+#             */
/*   Updated: 2019/11/05 14:33:05 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *p_dest;
	unsigned char *p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	while (n)
	{
		*p_dest = *p_src;
		if (*p_src == (unsigned char)c)
			return (p_dest + 1);
		p_dest++;
		p_src++;
		n--;
	}
	return (0);
}
