/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_of_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:10:55 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/25 12:20:54 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool			dealt_separator(t_list **input_list, int ret)
{
	t_token		*token;

	if (!*input_list)
		return (false);
	token = (*input_list)->content;
	*input_list = (*input_list)->next;
	if (token->type == and)
	{
		if (ret != SUCCESS)
			return (false);
	}
	else if (token->type == or)
	{
		if (ret == SUCCESS)
			return (false);
	}
	return (true);
}

/*
** 1-2-&&-3-4
**if nb_cmd == 0 this function will return un ptr on 1
** if nb_cmd == 1 this function will return pointer on 3
*/

t_list			*get_next_cmd(int nb_cmd)
{
	t_list		*tmp;
	t_token		*token;
	int			count;

	count = 0;
	tmp = g_info.list_input;
	while (nb_cmd && tmp)
	{
		token = tmp->content;
		if (is_separator(token->type) == true)
			count++;
		if (count == nb_cmd)
			return (tmp->next);
		tmp = tmp->next;
	}
	return (g_info.list_input);
}

static int		parsing(t_list *cmd, int nb_cmd)
{
	if ((iter_list_1(&cmd)) == ERROR)
		return (ERROR);
	cmd = get_next_cmd(nb_cmd);
	if ((iter_list_2(cmd)) == ERROR)
		return (ERROR);
	cmd = get_next_cmd(nb_cmd);
	if (iter_list_3(cmd) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void			special_case_redirection(t_list *current)
{
	t_list			*next_literal;
	t_list			*after_next_literal;

	next_literal = find_next_literal(current->next);
	if (next_literal)
		after_next_literal = find_next_literal(next_literal->next);
	swap_token(next_literal->content, after_next_literal->content);
	swap_token(current->content, next_literal->content);
}

void			btree_of_cmd(void)
{
	t_btree		*root;
	int			nb_cmd;
	t_list		*cmd;

	nb_cmd = 0;
	cmd = get_next_cmd(nb_cmd);
	while (cmd)
	{
		root = 0;
		if (parsing(cmd, nb_cmd) == ERROR)
			return ;
		cmd = get_next_cmd(nb_cmd);
		// ft_lstiter(cmd, print_token);
		// return ;
		build_ast(&root, &cmd);
		g_info.ptr = root;
		dealt_exec_cmd(root);
		ft_btree_clear(root, &btree_free_content);
		if (dealt_separator(&cmd, g_info.ret) == false)
			return ;
		nb_cmd++;
	}
}
