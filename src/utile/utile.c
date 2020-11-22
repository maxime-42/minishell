/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:59:24 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/22 15:38:05 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
void    print_token(void *ptr)
{
    t_token *token;
    char    *array;

	if (!ptr)
		return ;
    token = (t_token *)ptr;
    array = (char *)token->value;
	// printf("[%s] ", array);

	printf("[%s] type: [%d]\n", array, token->type);
}

void			error_msg(char *cmd_name, char *arg, char *msg)
{
	ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
}

void			btree_init_node(t_btree **node, t_token *token)
{
	*node = ft_btree_create_node(token);
	if (!*node)
	{
		exit(free_all(&g_info, ERROR));
	}
}

t_bool			check_permission(char *cmd)
{
	struct stat	permstat;
	t_bool		bool;

	ft_bzero(&permstat, sizeof(struct stat));
	stat(cmd, &permstat);
	bool = true;
	if ((permstat.st_mode & S_IFMT) == S_IFREG)
	{
		if ((permstat.st_mode & S_IXUSR) == 0)
		{
			error_msg("minishell: ", cmd, ": Permission denied\n");
			g_info.ret = PERMISSION_DENIED;
			bool = false;
		}
	}
	else if ((permstat.st_mode & S_IFMT) == S_IFDIR)
	{
		error_msg("minishell: ", cmd, ": Is a directory\n");
		g_info.ret = PERMISSION_DENIED;
		bool = false;
	}
	return (bool);
}

t_list			*skipt_space(t_list *list)
{
	t_token		*token;

	while (list)
	{
		token = list->content;
		if (token->type != space)
		{
			return (list);
		}
		list = list->next;
	}
	return (0);
}
