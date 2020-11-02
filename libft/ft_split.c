/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:32:23 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/30 16:55:34 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int				is_charset(char c, char *str)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int				nb_word(char *s, char *str)
{
	int	line;

	line = 0;
	if (s && !*s)
		return (line);
	line += (!(is_charset(*s, str)));
	while (s && *s && !(is_charset(*s, str)))
		s++;
	while (s && *s && (is_charset(*s, str)))
		s++;
	if (s && *s)
		return (line += nb_word(s, str));
	return (line);
}

int				nb_char(char *s, char *str)
{
	int		i;

	i = 0;
	while (s && *s && (is_charset(s[i], str)))
		s++;
	while (s && s[i] && !(is_charset(s[i], str)))
		i++;
	return (i);
}

static	char	**ft_free_array(char **array, int line)
{
	ft_putstr_fd("error:\nmalloc failure\n", 1);
	while (--line >= 0)
	{
		free(array[line]);
		array[line] = 0;
	}
	free(array);
	array = 0;
	return (0);
}

char			**ft_split(char *s, char *str)
{
	int		nb_w;
	int		i;
	int		j;
	char	**tab;

	i = -1;
	nb_w = nb_word(s, str);
	if (!(tab = malloc(sizeof(char *) * (nb_w + 1))))
		return (0);
	while (++i < nb_w)
	{
		while (*s && (is_charset(*s, str)))
			s++;
		if (*s && !(tab[i] = malloc(sizeof(char) * (nb_char(s, str) + 1))))
			return (ft_free_array(tab, i));
		j = 0;
		while (*s && !(is_charset(*s, str)))
		{
			tab[i][j++] = *s;
			s++;
		}
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
