/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_redirection_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:10:10 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/02 20:44:30 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

static	void		error_(char *file_name)
{
	ft_putstr_fd("bash: ", 1);
	ft_putstr_fd(file_name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
	g_info.ret = ERROR_BASH;
}

static int			get_file_descriptor(char **tab)
{
	int				i;
	int				fd;

	i = 0;
	while (tab[i])
	{
		if ((fd = open(tab[i], O_CREAT | O_RDWR | O_TRUNC, 0644)) == ERROR)
		{
			error_(tab[i]);
		}
		i++;
	}
	return (fd);
}

void				my_simple_redirection_right(t_btree *root)
{
	int				fd;
	t_token			*token;

	token = root->right->content;
	fd = get_file_descriptor(token->value);
	if (fork() == 0)
	{
		dup2(fd, 1);
		close(fd);
		dealt_exec_cmd(root->left);
		exit(g_info.ret);
	}
	wait(NULL);
}