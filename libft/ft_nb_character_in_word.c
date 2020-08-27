/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_character_in_word.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:16:52 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/24 12:21:25 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_nb_character_in_word(char *word)
{
    int count;

    count = 0;
    if (!word)
        return (count);
    while (word[count] && !ft_isspace(word[count]))
        count++;
    return (count);
}