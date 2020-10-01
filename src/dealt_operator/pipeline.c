/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:42:20 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/30 19:08:33 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

/*
** dup2(backup_fd, 0)					=>	connect read side of with stdin(standart input)
** dup2(fd[1], 1) 						=>	connecter the write side with stdout of process
** info->stack = to_del->next; 			=>	go to the next element in stack
** ft_lstdelone(to_del, &free_nothing); => 	pop top of stack 
*/

void				my_pipeline(t_info *info)
{
	int				fd[2];
	int				backup_fd;
	t_list			*to_del;

	backup_fd = 0;
	while (info->stack)
	{
		pipe(fd);
		if ((fork()) == 0)
		{
			dup2(backup_fd, 0);
			if (info->stack->next)
				dup2(fd[1], 1);
			close(fd[0]);
				dealt_command(info->stack->content);
			exit(info->ret);
		}
		wait(NULL);
		backup_fd = fd[0];
		close(fd[1]);
		to_del = info->stack;
		info->stack = to_del->next;
		ft_lstdelone(to_del, &free_nothing);
	}
}