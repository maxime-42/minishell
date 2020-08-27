/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:38:43 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/06 19:22:19 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		nb_word(char *s, char c)
{
	int	line;

	line = 0;
	while (s && *s && *s == c)
		s++;
	if (s && *s && *s != c)
		line++;
	while (s && *s && *s != c)
		s++;
	if (s && *s && *s == c)
		line += nb_word(s, c);
	return (line);
}

static	int		nb_char(char *s, char c)
{
	int	nbr_char;

	nbr_char = 0;
	while (s && s[nbr_char] && s[nbr_char] != c)
		nbr_char++;
	return (nbr_char);
}

char			**ft_split(char *s, char c)
{
	int			nb_w;
	int			i;
	int			j;
	char		**tab;

	i = -1;
	nb_w = nb_word(s, c);
	if (!s || !(tab = malloc(sizeof(char *) * (nb_w + 1))))
		return (0);
	while (++i < nb_w)
	{
		while (*s == c)
			s++;
		if (!(tab[i] = malloc(sizeof(char) * (nb_char(s, c) + 1))))
			return (0);
		j = 0;
		while (*s && *s != c)
		{
			tab[i][j++] = *s;
			s++;
		}
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
