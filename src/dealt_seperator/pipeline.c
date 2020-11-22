/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:42:20 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 21:29:59 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void				the_pipelines(t_btree *root, int count, int backup_fd)
{
	int				fd[2];
	int				pid;

	if (!root)
		return ;
	pipe(fd);
	if ((pid = fork()) == 0)
	{
		dup2(backup_fd, 0);
		if (count)
			dup2(fd[1], 1);
		close(fd[0]);
		if (count)
			dealt_exec_cmd(root->left);
		else
			dealt_exec_cmd(root);
		exit(g_info.ret);
	}
	close(fd[1]);
	the_pipelines(root->right, count - 1, fd[0]);
	pid = wait(NULL);
}
