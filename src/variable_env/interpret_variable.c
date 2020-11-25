/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:27:02 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/24 15:09:37 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
**	le but de cette fonction de trouver la valeur d'une variable
**	dans le tableau qui contient  les variable environementaz
**	exemple on a  ça comme token =  $ U S E R
**	etape 1:
**		supremer le sympole dollars
**	etpae 2: il reste U S E R
**		concatener tous le token du meme type dans un tableau
**	etape 3: on obtient un tableau qui contient : USER
**		aller chercher la string USER dans le tableau qui contient
**		les variable environement
*/

static void				dealt_value(t_token *token)
{
	char				*dup;
	int					ret;

	ret = ft_strcmp(token->value, "?");
	if (!ret)
		dup = ft_itoa(g_info.ret);
	else if (ret)
		dup = duplique_value_variable(g_info.list_env, token->value);
	ret = ft_strlen(token->value);
	ft_bzero(token->value, ret);
	if (dup)
	{
		free(token->value);
		token->value = dup;
		token->type = literal;
	}
}

int					interpret_variable(t_list **current)
{
	t_token			*token;
	t_list			*to_del;

	token = (*current)->content;
	if (token->type != variable)
		return (IS_NOT_VARIABLE);
	to_del = *current;
	if (!to_del->next || get_token_type(to_del->next->content) != literal)
	{
		return (ERROR);
	}
	*current = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	concate_token_same_type(current, literal);
	token = (*current)->content;
	dealt_value(token);
	return (SUCCESS);
}
