/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:52:01 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/25 13:53:08 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_free_string(void *ptr)
{
	char	*str;

	if (ptr)
	{
		ft_bzero(ptr, ft_strlen(ptr));
		str = (char *)ptr;
		free(str);
		str = 0;
	}
}
