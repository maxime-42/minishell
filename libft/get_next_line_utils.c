/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:16:01 by mkayumba          #+#    #+#             */
/*   Updated: 2019/11/14 14:35:24 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_concat(char *s1, char *s2, int len)
{
	char	*s3;
	int		i;
	int		j;
	int		size_s1;

	i = 0;
	size_s1 = 0;
	while ((j = -1) && s1 && s1[size_s1])
		size_s1++;
	if (!(s3 = malloc(sizeof(char) * (len + size_s1 + 1))))
		return (0);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && ++j < len)
	{
		s3[i] = s2[j];
		i++;
	}
	if (s1)
		free(s1);
	s3[i] = '\0';
	return (s3);
}

int			check_n(char *p)
{
	int		i;

	i = 0;
	while (p[i] && p[i] != '\n')
		i++;
	return (i);
}

int			handling_return(int r, char *buf, char **line, char *p)
{
	if (r > 0)
	{
		buf[r] = '\0';
		if (!(*line = ft_concat(p, buf, check_n(buf))))
			return (ERR_CODE);
		return (r);
	}
	else if (r == 0)
	{
		if (!*line)
			if (!(*line = ft_concat(0, 0, 0)))
				return (ERR_CODE);
		return (0);
	}
	*line = ft_concat(0, 0, 0);
	return (ERR_CODE);
}
