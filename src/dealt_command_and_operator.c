/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealt_command_and_operator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:59:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/30 19:53:58 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin			g_array_builtin[] = {
	{"echo", my_echo},
	{"cd", my_cd},
	{"pwd", my_pwd},
	{"export", my_export},
	{"unset", my_unset},
	{"env", my_env},
	{"exit", my_exit},
	{0, 0},
};

static t_operator			g_array_operator[] = {
	{and, NULL},
	{or, NULL},
	{redir_left, NULL},
	{redir_right, NULL},
	{semicolon, NULL},
	{pipeline, my_pipeline}
};

/*
** this function calls the function which corresponds to a operator 
** in the table of g_array_operator[] or command_systeme(&g_info, cmd);
*/

void						dealt_operator(t_btree **node)
{
	int						i;
	t_token					*token;

	i = -1;
	if (!node || !*node)
		return ;
	token = (*node)->content;
	if (is_operator(token->type) != true)
		return ;
	while (++i < NB_OPERATOR)
	{
		if (g_array_operator[i].type == token->type)
		{
			g_array_operator[i].ptr_fct(&g_info);
			return ;
		}
	}
}

/*
** this function calls the function which corresponds to a builtin in 
**the table of g_array_operator[] or command_systeme(&g_info, cmd);
*/

void					dealt_command(t_token *token)
{
	int					i;
	char				**cmd;

	i = -1;
	cmd = (char **)token->value;
	while (g_array_builtin[++i].value)
	{
		if (!ft_strcmp(g_array_builtin[i].value, cmd[0]))
		{
			g_array_builtin[i].ptr_fct(cmd);
			return ;
		}
	}
	exec_cmd_syst(&g_info, cmd);
}