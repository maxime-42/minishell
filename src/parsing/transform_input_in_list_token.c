/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input_in_list_token.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:31:18 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/05 17:39:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	le but de cette fonction consiste a
**	stranformer une string a un liste de token
**	etape 1:
**  dans cette fonction je met chaque charactere de
**	l'input dans une string => token_value
**	etape 2:
**	ensuite je definie le type de cette string
**	'token_value' avec la fonction get_type
**	etape 3:
**	ensuite je crée un token avec les attribue des etapes precedent 1 et 2
**	etape 4:
**  puis le token et mis dans un maillot puis un push addback
*/

static	t_token			g_array_token[] = {
	{"&", and},
	{"|", pipeline},
	{"<", simple_redir_left},
	{">", simple_redir_right},
	{";", semicolon},
	{"\"", double_quote},
	{"'", single_quote},
	{"\\", backslash},
	{"\f", space},
	{"\n", space},
	{"\r", space},
	{"\t", space},
	{"\v", space},
	{" ", space},
	{"$", variable},
	{0, 0},
};

/*
** cette fonction definie renvoyer un token en fonction du charactere
** qui est passer en parametre, selon le tableau de token
*/

static	t_token_type	type_of_token(char charset)
{
	int					i;
	char				*str;

	i = 0;
	while (g_array_token[i].value)
	{
		// if (!ft_strcmp(g_array_token[i].value, value))
		str = g_array_token[i].value;
		if (str[0] == charset)
		{
			return (g_array_token[i].type);
		}
		i++;
	}
	return (literal);
}

/*
** les but de transform_input_in_list_token et 
** de mettre chaque caractere dans un token 
*/
void					*transform_input_in_list_token(char *input)
{
	t_list				*new;
	char				*token_value;
	t_token				*token;

	g_info.list_input = 0; 
	while (input && *input)
	{
		if (!(token_value = ft_strndup(input, 1)))
			exit(free_all(&g_info, ERROR));
		if (!(token = create_token(token_value,	type_of_token(*token_value))))
			exit(free_all(&g_info, ERROR));
		if (!(new = ft_lstnew(token)))
			exit(free_all(&g_info, ERROR));
		ft_lstadd_back(&g_info.list_input, new);
		input++;
	}
}
