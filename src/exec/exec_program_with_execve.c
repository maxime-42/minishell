/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program_with_execve.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:45:38 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/25 14:02:32 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

static int		result_cmd(t_info *info, char **cmd, int ret)
{
	char		*msg_to_print;
	char		*msg;

	errno = 0;
	if (ret != ERROR)
		return (SUCCESS);
	ret = execve(cmd[0], cmd, info->tab_var_env);
	if (errno == ENOEXEC)
		return (SUCCESS);
	if (ret == ERROR)
	{
		msg = strerror(errno);
		msg_to_print = ft_strjoin(": ", msg);
		error_msg("minishell: ", cmd[0], msg_to_print);
		ft_putstr_fd("\n", 2);
		ft_strdel(&msg_to_print);
	}
	if (errno == EACCES)
		exit(PERMISSION_DENIED);
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

void			child_process(t_info *info, char **cmd)
{
	char		*path_cmd;
	t_list		*list_path;
	int			ret;

	ret = ERROR;
	list_path = info->list_path;
	while (ret != SUCCESS && list_path)
	{
		path_cmd = join_path_and_cmd(list_path->content, cmd[0]);
		ret = execve(path_cmd, cmd, info->tab_var_env);
		if (ret == ERROR)
			list_path = list_path->next;
		else
			ret = SUCCESS;
		ft_strdel(&path_cmd);
	}
	ret = result_cmd(info, cmd, ret);
	exit(ret);
}

void			father_process(t_info *info, int child_pid)
{
	int			child_status;

	child_status = 0;
	wait(&child_status);
	if (WIFSIGNALED(child_status))
	{
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

	bool = check_permission(cmd[0]);
	if (bool == false)
		return ;
	update_tab_var_env(info->list_env);
	update_cmd_path(info);
	if (!info->list_path)
	{
		error_msg("minishell: ", cmd[0], ": path is empty\n");
		info->ret = ERROR_BASH;
		return ;
	}
	if ((pid = fork()) == 0)
		child_process(info, cmd);
	else
		father_process(info, pid);
}
