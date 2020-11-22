/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:53:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/22 14:29:39 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

static void			error_(char *file_name)
{
	ft_putstr_fd("minishell: ", 1);
	ft_putstr_fd(file_name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
	g_info.ret = ERROR_BASH;
}

static int			fd_simple_redirection_right(char **tab)
{
	int				i;
	int				fd;

	i = 0;
	while (tab[i])
	{
		fd = open(tab[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == ERROR)
		{
			error_(tab[i]);
		}
		i++;
	}
	return (fd);
}

static int			fd_double_redirection_right(char **tab)
{
	int				i;
	int				fd;

	i = 0;
	while (tab[i])
	{
		fd = open(tab[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == ERROR)
		{
			error_(tab[i]);
		}
		i++;
	}
	return (fd);
}

static int			fd_simple_redirection_left(char **tab)
{
	int				i;
	int				fd;

	i = 0;
	while (tab[i])
	{
		fd = open(tab[i], O_RDONLY);
		if (fd == ERROR)
		{
			error_(tab[i]);
		}
		i++;
	}
	return (fd);
}

void				redirections(t_btree *root)
{
	int				fd;
	t_token			*token;
	int				redirection;

	redirection = 1;
	token = root->content;
	if (token->type == simple_redir_right)
		fd = fd_simple_redirection_right(get_token_value(root->right->content));
	else if (token->type == double_redir_right)
		fd = fd_double_redirection_right(get_token_value(root->right->content));
	else if (token->type == simple_redir_left)
	{
		fd = fd_simple_redirection_left(get_token_value(root->right->content));
		redirection = 0;
	}
	if (fork() == 0)
	{
		dup2(fd, redirection);
		close(fd);
		dealt_exec_cmd(root->left);
		exit(g_info.ret);
	}
	wait(NULL);
}
