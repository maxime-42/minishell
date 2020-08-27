/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:41:34 by mkayumba          #+#    #+#             */
/*   Updated: 2019/11/15 14:11:56 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	i = 0;
	int			r;
	char		*p;

	if (!line)
		return (ERR_CODE);
	p = 0;
	*line = 0;
	while (BUFFER_SIZE > 0)
	{
		if (i && !(*line = ft_concat(p, buf + i, check_n(buf + i))))
			return (ERR_CODE);
		else if (!i && (r = read(fd, buf, BUFFER_SIZE)) >= -1)
			if ((handling_return(r, buf, line, p)) <= 0)
				return (r);
		p = *line;
		i += check_n(buf + i) + 1;
		if (!buf[i - 1])
			i = 0;
		if (buf[i - 1] == '\n')
			return (1);
	}
	return (ERR_CODE);
}
