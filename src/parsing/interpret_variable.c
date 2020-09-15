/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:27:02 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/14 11:59:50 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	le but de cette fonction de trouver la valeur d'une variable
**	dans le tableau qui contient  les variable environementaz
**	exemple on a  ça comme token =  $ U S E R
**	etape 1:
**		supremier le sympole dollars
**	etpae 2: il reste U S E R
**		concatener tous le token du meme type dans un tableau
**	etape 3: on obtient un tableau qui contient USER
**		aller chercher la string USER dans le tableau qui contient
**		les variable environement
*/

void				interpret_variable(t_list **current)
{
	t_token_type	type;
	char			**name;
	t_token			*token;
	char			*value;
	t_list			*to_del;

	if (get_type_of_token(current) != variable)
		return ;
	to_del = *current;
	*current = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	type = get_type_of_token(current);
	concate_token_same_type(current, type);
	token = (*current)->content;
	name = token->value;
	value = duplique_value_variable(g_info.list_env, name[0]);
	if (value)
	{
		free(name[0]);
		token->type = literal;
		name[0] = value;
	}
}
