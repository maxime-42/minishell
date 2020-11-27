/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program_with_execve.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:45:38 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/27 19:00:43 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void			child_process(t_info *info, char **cmd, char *path_absolut)
{
	int			ret;

	if (!path_absolut)
		path_absolut = cmd[0];
	ret = execve(path_absolut, cmd, info->tab_var_env);
	exit(ret);
}

void			father_process(t_info *info, int child_pid)
{
	int			child_status;

	child_status = 0;
	signal(SIGINT, SIG_IGN);
	wait(&child_status);
	if (WIFSIGNALED(child_status))
	{
		ft_putstr_fd("\n", 2);
		g_info.ret = WTERMSIG(child_status);
	}
	if (WIFEXITED(child_status))
	{
		info->ret = child_status;
	}
	g_info.ret = WEXITSTATUS(child_status);
	(void)child_pid;
	(void)info;
}

void			exec_cmd_syst(t_info *info, char **cmd)
{
	int			pid;
	t_bool		bool;
	char		*path_absolut;

	bool = true;
	update_tab_var_env(info->list_env);
	path_absolut = get_absolut_path(cmd);
	if (!path_absolut)
		bool = check_permission(cmd[0]);
	else
		bool = check_permission(path_absolut);
	if (bool == false)
	{
		ft_strdel(&path_absolut);
		return ;
	}
	if ((pid = fork()) == 0)
		child_process(info, cmd, path_absolut);
	else
		father_process(info, pid);
	ft_strdel(&path_absolut);
}
