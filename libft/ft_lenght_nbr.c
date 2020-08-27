/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:24:07 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 19:24:31 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lenght_nbr(int nb)
{
	int	size_nb;
	int	result;

	result = 1;
	size_nb = 0;
	while (result)
	{
		result = nb / 10;
		nb = result;
		size_nb++;
	}
	return (size_nb);
}
