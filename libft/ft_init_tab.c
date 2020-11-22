/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:22:19 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/22 15:09:13 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_tab(char **tab, int nb_line)
{
	int	line;

	line = 0;
	while (line < nb_line)
	{
		tab[line++] = 0;
	}
	tab[line] = 0;
}
