/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:59:24 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/26 14:37:38 by mkayumba         ###   ########.fr       */
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
	printf("[%s] type: [%d]\n", array, token->type);
}


void				print_tab(char **tab)
{
	int				i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		printf("tab => [%s]\n", tab[i++]);
	}
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

static t_bool	is_executable(struct stat	permstat, char *name)
{
	t_bool		bool;

	bool = true;
	if ((permstat.st_mode & S_IFMT) == S_IFREG)
	{
		if ((permstat.st_mode & S_IXUSR) == 0)
		{
			error_msg("minishell: ", name, ": Permission denied\n");
			g_info.ret = PERMISSION_DENIED;
			bool = false;
		}
	}
	else if ((permstat.st_mode & S_IFMT) == S_IFDIR)
	{
		error_msg("minishell: ", name, ": Is a directory\n");
		g_info.ret = PERMISSION_DENIED;
		bool = false;
	}
	return (bool);
}

t_bool			check_permission(char *cmd)
{
	struct stat	permstat;
	t_bool		bool;
	int			ret;
	
	ft_bzero(&permstat, sizeof(struct stat));
	ret = stat(cmd, &permstat);
	if (ret == ERROR)
	{
		error_msg("minishell: ", cmd, ": command not found\n");
		g_info.ret = ERROR_BASH;
		return (false);
	}
	bool = is_executable(permstat, cmd);
	return (bool);
}