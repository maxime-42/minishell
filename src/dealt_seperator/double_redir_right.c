/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_redir_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:40:27 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/02 21:13:43 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

void				error_(char *file_name)
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
		fd = open(tab[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == ERROR)
		{
			error_(tab[i]);
		}
		i++;
	}
	return (fd);
}

void				my_double_redirection_right(t_btree *root)
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
		exit (g_info.ret);
	}
	wait(NULL);
}


// void				my_double_redirection_right(t_info *info)
// {
// 	(void)info;
// 	int				fd;
// 	t_token			*token;
// 	char			*file_name;
	
// 	if (!info->stack)
// 		return ;
// 	token = get_command(&info->stack);
// 	file_name = get_file_name(&info->stack);
// 	if ((fd = open(file_name, O_CREAT | O_RDWR | O_APPEND, 0644)) == ERROR)
// 	{
// 		error_(file_name);
// 		return ;
// 	}
// 	if (fork() == 0)
// 	{
// 		dup2(fd, 1);
// 		close(fd);
// 		dealt_command(token);
// 		exit (info->ret);
// 	}
// 	wait(NULL);
// }