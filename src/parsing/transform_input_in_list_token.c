/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input_in_list_token.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:31:18 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/06 15:24:37 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	le but de cette fonction consiste a
**	stranformer une string a un liste de token
**	etape 1:
**  dans cette fonction je met chaque charactere de
**	l'input dans une string => value
**	etape 2:
**	ensuite je definie le type de cette string
**	'value' avec la fonction get_type
**	etape 3:
**	ensuite je crée un token avec les attribue des etapes precedent 1 et 2
**	etape 4:
**  puis le token et mis dans un maillot puis un push addback
*/

static	t_token			g_tab_token[] = {
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
	while (g_tab_token[i].value)
	{
		// if (!ft_strcmp(g_tab_token[i].value, value))
		str = g_tab_token[i].value;
		if (str[0] == charset)
		{
			return (g_tab_token[i].type);
		}
		i++;
	}
	return (literal);
}

/*
** les but de transform_input_in_list_token et 
** de mettre chaque caractere dans un token 
*/
void					transform_input_in_list_token(char *input)
{
	t_list				*new;
	char				*value;
	t_token				*token;

	g_info.list_input = 0; 
	while (input && *input)
	{
		if (!(value = malloc(sizeof(char) * (2))))
			exit(free_all(&g_info, ERROR));
		value[0] = input[0];
		value[1] = '\0';
		if (!(token = create_token(value, type_of_token(*value))))
			exit(free_all(&g_info, ERROR));
		if (!(new = ft_lstnew(token)))
			exit(free_all(&g_info, ERROR));
		ft_lstadd_back(&g_info.list_input, new);
		input++;
	}
}
