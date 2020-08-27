/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:25:06 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 19:25:08 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] && str[i] && to_find[i] == str[i])
		i++;
	if (to_find[i] && str[i] && to_find[i] != str[i])
		return (ft_strstr(str + 1, to_find));
	if (!to_find[i] && str[i])
		return (str);
	if (!to_find[i] && !str[i])
		return (str);
	return (0);
}
