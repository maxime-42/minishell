/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:44:24 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/02 22:25:02 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	while (n--)
		*(p_dest++) = *(p_src++);
	return (dest);
}
