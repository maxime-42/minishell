/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:24:41 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/24 14:37:48 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	fonction create_token:
**	la fonction factor créer un token et l'initialiser
**	le token est initialiser avec les variable qui sont passer en parametre
*/
t_token				*create_token(char *token_value, t_token_type token_type)
{
	t_token			*token;
	int				size;

	size = sizeof(t_token);
	token = malloc(size);
	if (!token)
	{
		exit(free_all(&g_info, ERROR));
	}
	token->value = token_value;
	token->type = token_type;
	return (token);
}
