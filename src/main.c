/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:39:25 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/28 14:56:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  si s1 < s2 retour negatif
**  si si s1 > retour positive 
*/
#include "minishell.h"
#include <signal.h>

// void			prompt()
// {

// 	ft_putstr_fd(">", 0);
// 	get_next_line(0, &g_info.str_input);
// 	if (!ft_strlen(g_info.str_input))
//         free_all(&g_info, ERROR);
// }

void			print_list(void *content)
{
	t_list		*ptr;
	t_token		*token;
	
	ptr = content;
	while (ptr)
	{
		//printf("hellow\n");
		token = (t_token *) ptr->content;
		// printf("%s ", (char *)token->value);
		ft_putstr_fd((char *)token->value, 1);
		ptr = ptr->next;
	}
	// printf("\n");
}

int             main(int ac, char **av, char **env)
{
    g_info.list_env = init_env(env);
    g_info.list_path = 0;
    g_info.stack = 0;
	g_info.ret = 0;
	g_info.root = 0;
	g_info.tab_var_env = 0;
	g_info.str_input = 0;
	g_info.size_tab = 0;
	int r = 0;
    while (1)
    {
		ft_putstr_fd(">", 0);
		signal(SIGINT, &handle_sig_int);
		signal(SIGQUIT, &handle_sig_quit);
		r = get_next_line(0, &g_info.str_input);
		if (g_info.str_input[0] == '\0' && r == 0)
		{
			// printf("1ere if : ");
			// printf("\nr = [%d] | input = [%s]\n", r, g_info.str_input);
			return (free_all(&g_info, ERROR));
		}
		update_tab_var_env(g_info.list_env);
		update_cmd_path(&g_info);
		parsing_input(g_info.str_input);
		put_input_list_in_btree(&g_info.root, g_info.list_input);
		// printf("\n");
		// create_ast(&g_info.root, g_info.list_input);
		//printf("______ast_________\n");
		ft_btree_dfs_inorder(g_info.root, &print_list);
		//ft_lstiter(g_info.list_input, &print_token);
		// exec_cmd(&g_info, g_info.root);
		// exit(free_all(&g_info, ERROR));
		free_all(&g_info, 0);
    }
	(void)ac;
	(void)av;
	(void)env;
	return (g_info.ret);
}
