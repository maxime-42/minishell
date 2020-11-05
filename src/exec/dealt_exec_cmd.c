/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealt_exec_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:59:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/05 21:48:17 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin	g_tab_builtin[] = {
	{"echo", my_echo},
	{"cd", my_cd},
	{"pwd", my_pwd},
	{"export", my_export},
	{"unset", my_unset},
	{"env", my_env},
	{"exit", my_exit},
	{0, 0},
};

static void			find_cmd(t_token *token)
{
	int				i;
	char			**cmd;

	i = -1;
	cmd = (char **)token->value;
	while (g_tab_builtin[++i].value)
	{
		if (!ft_strcmp(g_tab_builtin[i].value, cmd[0]))
		{
			g_tab_builtin[i].ptr_fct(cmd);
			return ;
		}
	}
	exec_cmd_syst(&g_info, cmd);
}

void				dealt_exec_cmd(t_btree *root)
{
	t_token_type	type;

	if (!root)
		return ;
	type = get_token_type(root->content);
	if (type == literal)
		find_cmd(root->content);
	else if (is_right_side_redirection(type) || type == simple_redir_left)
		redirections(root);
	else if (type == pipeline)
		the_pipelines(root, 1, 0);
}