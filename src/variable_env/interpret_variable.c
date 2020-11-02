/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:27:02 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/31 19:46:43 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void			if_is_var_status(char **value_var, char *name)
{
	if (!value_var[0][0])
	{
		if (!(ft_strcmp(name, "?")))	
		{
			ft_free_string(value_var[0]);
			value_var[0] = ft_itoa(g_info.ret);
		}
	}
}
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
void				interpret_variable(t_list **current)
{
	t_token_type	type;
	t_token			*token;
	char			*value;
	t_list			*to_del;

	if (get_token_type((*current)->content) != variable)
		return ;
	to_del = *current;
	*current = to_del->next;
	ft_list_remove_current_node(&g_info.list_input, to_del, clear_token);
	type = get_token_type((*current)->content);
	concate_token_same_type(current, type);
	token = (*current)->content;
	value = duplique_value_variable(g_info.list_env, token->value);
	if (value)
	{
		if_is_var_status(&value, token->value);
		ft_free_string(token->value);
		token->type = literal;
		token->value = value;
	}
}
