/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occurance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:18:03 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 19:18:33 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_occurance(char *s1, char *s2)
{
	int	index_s1;
	int	index_s2;

	index_s1 = -1;
	while (s1[++index_s1])
	{
		index_s2 = -1;
		while (s2[++index_s2])
		{
			if (s1[index_s1] == s2[index_s2])
				return (1);
		}
	}
	return (0);
}
