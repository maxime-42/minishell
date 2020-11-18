/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_of_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:10:55 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/16 17:05:12 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool		dealt_separator(t_list **input_list, int ret)
{
	t_token *token;

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

t_list		*get_next_cmd(int nb_cmd)
{
	t_list	*tmp;
	t_token	*token;
	int		count;
	
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

void		btree_of_cmd()
{
	t_btree	*root;
	int		nb_cmd;
	t_bool	bool;
	t_list	*cmd;

	nb_cmd = 0;
	cmd = get_next_cmd(nb_cmd);
	while (cmd)
	{
		root = 0;
		if ((iter_list_1(&cmd)) == ERROR)
		{
			printf("btree_of_cmd error !!!\n");
			return ;
		}
		// return ;
		cmd = get_next_cmd(nb_cmd);
		if ((iter_list_2(cmd)) == ERROR)
			return ;
		cmd = get_next_cmd(nb_cmd);
		build_ast(&root, &cmd);
		g_info.ptr = root;
		dealt_exec_cmd(root);
		// ft_btree_dfs_inorder(root, &print_token_tab);
		// printf("\n\n");
		// print_token_tab(root->content);
		ft_btree_clear(root, &btree_free_content);
		bool = dealt_separator(&cmd, g_info.ret);
		if (bool == false)
			return ;
		nb_cmd++;
	}
}