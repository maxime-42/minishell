/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:24:41 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/29 16:44:18 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token				*create_token(void *token_value, t_token_type token_type)
{
	t_token			*token;
	int				size;

	size = sizeof(t_token);
	token = malloc(size);
	if (!token || !token_value)
	{
		exit(free_all(&g_info, ERROR));
	}
	token->value = token_value;
	token->type = token_type;
	return (token);
}
