/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_syst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:45:38 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/19 18:56:39 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

static	int	error_(char *cmd)
{
	ft_putstr_fd("bash:", 1);
	ft_putstr_fd(cmd, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
	return (ERROR_BASH);
}

static char		*join_path_and_cmd(char *path, char *cmd)
{
	char		*join_path_and_cmd;

	join_path_and_cmd = ft_strjoin(path, cmd);
	if (!join_path_and_cmd)
	{
		ft_putstr_fd("error:\nmalloc failure\n", 1);
		exit(free_all(&g_info, ERROR));
	}
	return (join_path_and_cmd);
}

static void		child_process(t_info *info, char **cmd)
{
	char		*path_cmd;
	t_list		*list_path;
	int		 	ret;

	ret = SUCCESS;
	list_path =  info->list_path;
	if ((ret = execve(cmd[0], cmd, info->tab_var_env)) == ERROR)
	{
		while (ret != SUCCESS && list_path)
		{
			path_cmd = join_path_and_cmd(list_path->content, cmd[0]);
			if ((ret = execve(path_cmd, cmd, info->tab_var_env)) == ERROR)
				list_path = list_path->next;
			else
				ret = SUCCESS;
			ft_free_string(path_cmd);
		}
	}
	if (ret != SUCCESS)
		exit(error_(cmd[0]));
	exit(SUCCESS);
}

static void		father_process(t_info *info, int child_pid)
{
	int			child_status;

	child_status = 0;
	
	wait(&child_status);
	if (WIFSIGNALED(child_status))
	{
		//printf("______process finish by a signal__________");
		if (WTERMSIG(child_status) == SIGINT)
			g_info.ret = SIGINT;
	}
	if (WIFEXITED(child_status))
	{
		;
		// info->ret = child_status;
		// printf("quel by ret = %d\n", ret);
		// printf("info.ret = %d\n", g_info.ret);
		// printf("_____________everything finish normally__________\n");
	}
	g_info.ret = WEXITSTATUS(child_status);
	// if (WTERMSIG(child_status) == SIGSEGV)
	// {
	//	 ft_putstr_fd("Segmentation fault\n", 1);
	//	 info->ret = 139;
	// }
	// else if (WTERMSIG(child_status) == SIGFPE)
	// {
	//	 ft__putstr_fd("Floating exception\n", 1);
	//	 info->ret = 136;
	// }
	// else
	// {
	//  if (((info->ret = WEXITSTATUS(child_status))) == ERROR)
	//		 exit(ERROR);
	// }
	(void)child_pid;
	(void)info;
}

void			exec_cmd_syst(t_info *info, char **cmd)
{
	int			pid;

	if (!info->list_path)
		return ;
	if ((pid = fork())== 0)
	{
		child_process(info, cmd);
	}
	else if (pid == ERROR)
	{
		ft_putstr_fd(strerror(errno), 1);
		exit(free_all(&g_info, ERROR));
	}
	else
	{
		father_process(info, pid);
	}
}