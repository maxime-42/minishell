/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_redir_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:35:40 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/02 21:16:46 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

// static int			get_file_descriptor(char **tab)
// {
// 	int				i;
// 	int				fd;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		if ((fd = open(tab[i], O_RDONLY)) == ERROR)
// 		if (fd == ERROR)
// 		{
// 			error_(tab[i]);
// 		}
// 		i++;
// 	}
// 	return (fd);
// }

// void				my_simple_redirection_left(t_btree *root)
// {
// 	int				fd;
// 	t_token			*token;

// 	token = root->right->content;
// 	fd = get_file_descriptor(token->value);
// 	if (fork() == 0)
// 	{
// 		dup2(fd, 0);
// 		close(fd);
// 		dealt_command(token);
// 		exit (g_info.ret);
// 	}
// 	wait(NULL);
// }

// void				my_simple_redirection_left(t_info *info)
// {
// 	(void)info;
// 	int				fd;
// 	t_token			*token;
// 	char			*file_name;

// 	if (!info->stack)
// 		return ;
// 	token = get_command(&info->stack);
// 	file_name = get_file_name(&info->stack);
// 	if ((fd = open(file_name, O_RDONLY)) == ERROR)
// 	{
// 		error_(file_name);
// 		return ;
// 	}
// 	if (fork() == 0)
// 	{
// 		dup2(fd, 0);
// 		close(fd);
// 		dealt_command(token);
// 		exit (info->ret);
// 	}
// 	wait(NULL);
// }