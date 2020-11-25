/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:53:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/23 15:57:30 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

static int			fd_simple_redirection_right(char **tab)
{
	int				i;
	int				fd;
	char			*join;

	i = 0;
	while (tab[i])
	{
		fd = open(tab[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == ERROR)
		{
			join = ft_strjoin(tab[i], ": ");
			error_msg("minishell: ", join, strerror(errno));
			ft_putstr_fd("\n", 2);
			g_info.ret = ERROR_REDIRECTION;
			free(join);
			return (fd);
		}
		i++;
	}
	return (fd);
}

static int			fd_double_redirection_right(char **tab)
{
	int				i;
	int				fd;
	char			*join;

	i = 0;
	while (tab[i])
	{
		fd = open(tab[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == ERROR)
		{
			join = ft_strjoin(tab[i], ": ");
			error_msg("minishell: ", join, strerror(errno));
			ft_putstr_fd("\n", 2);
			g_info.ret = ERROR_REDIRECTION;
			free(join);
			return (fd);
		}
		i++;
	}
	return (fd);
}

static int			fd_simple_redirection_left(char **tab)
{
	int				i;
	int				fd;
	char			*join;

	i = 0;
	while (tab[i])
	{
		fd = open(tab[i], O_RDONLY);
		if (fd == ERROR)
		{
			join = ft_strjoin(tab[i], ": ");
			error_msg("minishell: ", join, strerror(errno));
			ft_putstr_fd("\n", 2);
			g_info.ret = ERROR_REDIRECTION;
			free(join);
			return (fd);
		}
		i++;
	}
	return (fd);
}

static int			create_file(t_token_type type, char **file_name)
{
	int				fd;
	
	if (type == simple_redir_right)
		fd = fd_simple_redirection_right(file_name);
	else if (type == double_redir_right)
		fd = fd_double_redirection_right(file_name);
	else if (type == simple_redir_left)
		fd = fd_simple_redirection_left(file_name);
	return (fd);
}

void				redirections(t_btree *root)
{
	int				fd;
	t_token			*token;
	int				redirection;
	char			**tab;

	redirection = 1;
	tab = get_token_value(root->right->content);
	token = root->content;
	if (token->type == simple_redir_left)
		redirection = 0;
	fd = create_file(token->type, tab);
	if (fd != ERROR && fork() == 0)
	{
		dup2(fd, redirection);
		close(fd);
		dealt_exec_cmd(root->left);
		exit(g_info.ret);
	}
	wait(NULL);
}
