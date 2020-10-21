/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input_in_list_token.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:31:18 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/19 12:38:45 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
**The goal of this file consist to create a list (linked list ) of token
**who content one character of input string 
*/

/*
**	fonction create_token:
**	la fonction factor créer un token et l'initialiser
**	le token est initialiser avec les variable qui sont passer en parametre
*/

/*
** Each character  will be identifier by one of these types
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
	{"?", status},
	{0, 0},
};
/*
** type_of_token(char charset)
** This function defines the type of token for the character inside token
** the type of token depend of table => g_tab_token
*/
static	t_token_type	type_of_token(char charset)
{
	int					i;
	char				*str;

	i = 0;
	while (g_tab_token[i].value)
	{
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
** transform_input_in_list_token
** This function puts each character of string input in token,
** then put this token in linked list
**Step one get one character of the input string 
**step two create token with this character 
**step three add this token in linked list
*/
void					transform_input_in_list_token(char *input)
{
	t_list				*new;
	char				*value;
	t_token				*token;

	value = 0;
	g_info.list_input = 0; 
	while (input && *input)
	{
		value = ft_strnew(2);
		if (!value)
			exit(free_all(&g_info, ERROR));
		value[0] = input[0];
		token = create_token(value, type_of_token(*value));
		if (!(new = ft_lstnew(token)))
			exit(free_all(&g_info, ERROR));
		ft_lstadd_back(&g_info.list_input, new);
		input++;
	}
}
