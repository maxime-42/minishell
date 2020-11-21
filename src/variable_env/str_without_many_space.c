/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_without_many_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:56:20 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 16:50:11 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			*need_new_str(t_token *token)
{
	char			**tab;
	int				size;
	char			*new;

	new = 0;
	tab = ft_split((char *)token->value, " ");
	if (!tab)
	{
		ft_free_double_array(tab);
		return (new);
	}
	size = ft_strlen(token->value);
	new = ft_strnew(size + 1);
	free(token->value);
	token->value = tab;
	return (new);
}

/*
** this function return new string without extrat space
** example str = "a    b     c"
** str_whithout_many_space will return a string new_str = "a b c"
*/
void				str_whithout_many_space(t_token *token)
{
	char			*new_str;
	char			**tab;
	int				i;
	int				size;

	i = -1;
	size = 0;
	new_str = need_new_str(token);
	if (!new_str)
		return ;
	tab = token->value;
	while (tab[++i])
	{
		strcpy(new_str + size, tab[i]);
		size = ft_strlen(new_str);
		if (tab[i + 1])
			new_str[size++] = ' ';
	}
	ft_free_double_array(token->value);
	token->value = new_str;
}