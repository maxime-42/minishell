/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:27:02 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/19 18:16:38 by mkayumba         ###   ########.fr       */
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
static void			get_status_cmd(t_list **current)
{
	t_token			*token;
	char			**value;

	token = (*current)->content;
	value = token->value;
	ft_free_string(value[0]);
	value[0] = ft_itoa(g_info.ret);
	token->type = literal;
	if (!value[0])
	{
		exit(free_all(&g_info, ERROR));
	}
}

void				interpret_variable(t_list **current)
{
	t_token_type	type;
	char			**name;
	t_token			*token;
	char			*value;
	t_list			*to_del;

	if (get_token_type((*current)->content) != variable)
		return ;
	to_del = *current;
	*current = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	type = get_token_type((*current)->content);
	if (type == status)
		get_status_cmd(current);
	else
	{
		concate_token_same_type(current, type);
		token = (*current)->content;
		name = token->value;
		value = duplique_value_variable(g_info.list_env, name[0]);
		if (value)
		{
			ft_free_string(name[0]);
			token->type = literal;
			name[0] = value;
		}
	}
}
