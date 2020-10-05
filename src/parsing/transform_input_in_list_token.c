/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input_in_list_token.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:31:18 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/02 17:34:18 by mkayumba         ###   ########.fr       */
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
	{"&&", and},
	{"||", or},
	{"|", pipeline},
	{"<", simple_redir_left},
	{">", simple_redir_right},
	{"<<", double_redir_left},
	{">>", double_redir_right},
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

t_bool					is_operator(t_token_type type)
{
	if ((type >= 0 && type < NB_OPERATOR))
		return (true);
	return (false);
}

static	int				clear(t_list **begin)
{
	ft_lstclear(begin, &clear_token);
	return (ERROR);
}

static	t_token_type	define_type_of_token(char *value)
{
	int					i;

	i = 0;
	while (g_array_token[i].value)
	{
		if (!ft_strcmp(g_array_token[i].value, value))
		{
			return (g_array_token[i].type);
		}
		i++;
	}
	return (literal);
}

/*
** ici je copie les character de l'input dans "dest" qui est la valeur du token
** src ce l'input
** si le charater courrent :
**	 || ou && >> on copie les deux character de l'input 
**	 dans dest (index et index + 1)
** sinon on copie qu'un seul character de l'input dans dest
*/
static int				copy_(char *dest, char *src, int index_src)
{
	if (src[index_src] == '>' && src[index_src + 1] == '>')
	{
		dest[0] = src[index_src++];
		dest[1] = src[index_src];
	}
	else if (src[index_src] == '|' && src[index_src + 1] == '|')
	{
		dest[0] = src[index_src++];
		dest[1] = src[index_src];
	}	
	else if (src[index_src] == '&' && src[index_src + 1] == '&')
	{
		dest[0] = src[index_src++];
		dest[1] = src[index_src];
	}
	else
		dest[0] = src[index_src];
	return (index_src);
}

t_list					*transform_input_in_list_token(char *input)
{
	t_list				*begin;
	t_list				*new;
	int					index_input;
	char				*token_value;
	t_token				*token;

	begin = 0;
	index_input = -1;
	while (input[++index_input])
	{
		if (!(token_value = ft_strnew(4)))
			exit(clear(&begin));
		index_input = copy_(token_value, input, index_input);
		if (!(token = create_token(token_value,
		define_type_of_token(token_value))))
		{
			exit(clear(&begin));
		}
		if (!(new = ft_lstnew(token)))
			exit(clear(&begin));
		ft_lstadd_back(&begin, new);
	}
	return (begin);
}
