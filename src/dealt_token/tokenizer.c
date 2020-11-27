/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:31:18 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/27 18:11:54 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

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
	{0, 0},
};

/*
** type_of_token(char charset)
** This function defines the type of token for the character inside token
** the type of token depend of table => g_tab_token
*/

static t_token_type		define_type(char charset)
{
	int					i;
	char				*str;
	t_token_type		type;

	i = 0;
	type = literal;
	while (g_tab_token[i].value)
	{
		str = g_tab_token[i].value;
		if (str[0] == charset)
		{
			type = g_tab_token[i].type;
			return (type);
		}
		i++;
	}
	return (type);
}

/*
** this function is a Tokenization it dividing each character in token.
** this function transforme input string in sequence of token
** This function puts each character of string input in token,
** then put this token in linked list
** Step one get one character of the input string
** step two create token with this character
** step three add this token in linked list
*/

void					tokenizer(char *input)
{
	t_list				*new;
	char				*value;
	t_token				*token;
	t_token_type		type;

	value = ft_strdup(input);
	if (!value)
		exit(free_all(&g_info, ERROR));
	type = define_type(value[0]);
	token = create_token(value, type);
	if (!(new = ft_lstnew(token)))
		exit(free_all(&g_info, ERROR));
	ft_lstadd_back(&g_info.list_input, new);
}

static void				handler_ctrl_d(char *buf, int r)
{
	if (!g_info.list_input)
	{
		ft_putstr_fd("exit\n", 1);
		exit(free_all(&g_info, ERROR));
	}
	else
		buf[r] = '\0';	
}

void					promp(void)
{
	char				buf[2];
	int					r;
	int					i;

	i = 0;
	buf[0] = '\0';
	ft_putstr_fd("->", 1);
	while (buf[0] != '\n')
	{
		r = read(0, buf, 1);
		buf[r] = '\0';
		if (buf[0] == CTRL_D)
			handler_ctrl_d(buf, r);
		else if (buf[0] != '\n')
		{
			i++;
			if (i == 1)
				tokenizer(" ");
			tokenizer(buf);
		}
	}
}
