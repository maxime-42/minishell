/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:34:39 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/06 19:26:19 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *nptr)
{
	long	n;
	int		s;
	int		ovf;

	n = 0;
	s = 1;
	ovf = 1;
	while ((*nptr && *nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if ((*nptr && *nptr == '-') || *nptr == '+')
	{
		if (*nptr == '-')
			s *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && ovf == 1)
	{
		n = (n * 10) + *nptr++ - 48;
		if (n < 0 && s == 1)
			ovf = -1;
		else if (n < 0 && s == -1)
			ovf = 0;
	}
	return (ovf == 1 ? n * s : ovf);
}
