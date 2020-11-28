/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:53:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 13:26:14 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

static void			exec_redirection(t_btree *root, int fd, int redirection)
{
	int				child_status;

	child_status = 0;
	if (fork() == 0)
	{
		dup2(fd, redirection);
		close(fd);
		dealt_exec_cmd(root->left);
		exit(g_info.ret);
	}
	else
	{
		wait(&child_status);
		g_info.ret = WEXITSTATUS(child_status);
	}
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
	if (fd == ERROR)
		return ;
	exec_redirection(root, fd, redirection);
}
