/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program_with_execve.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:45:38 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/18 20:11:43 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

t_bool			check_permission(char *cmd)
{
	struct stat permstat;
	t_bool	bool;
	
	ft_bzero(&permstat, sizeof(struct stat));
	stat(cmd, &permstat);
	bool = true;
	if ((permstat.st_mode & S_IFMT) == S_IFREG)
	{
		if ((permstat.st_mode & S_IXUSR) == 0)
		{
			error_msg("minishell: ", cmd, ": Permission denied\n");
			g_info.ret = PERMISSION_DENIED;
			bool = false;
		}
	}
	else if ((permstat.st_mode & S_IFMT) == S_IFDIR)
	{
		error_msg("minishell: ", cmd, ": Is a directory\n");
		g_info.ret = PERMISSION_DENIED;
		bool = false;
	}
	return (bool);
}

int				result_cmd(t_info *info, char **cmd, int ret)
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
		exit (PERMISSION_DENIED);
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
	int		 	ret;

	ret = ERROR;
	list_path =  info->list_path;
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

void		father_process(t_info *info, int child_pid)
{
	int			child_status;

	child_status = 0;
	
	wait(&child_status);
	if (WIFSIGNALED(child_status))
	{
		//printf("______process finish by a signal__________");
		g_info.ret = WTERMSIG(child_status);
	// 	if (WTERMSIG(child_status) == SIGINT)
	// 		g_info.ret = SIGINT;
	// 	else if (WIFSTOPPED(child_status))
	// 		g_info.ret = WSTOPSIG(child_status);
	// 	if (WIFSIGNALED(child_status))
	// 		g_info.ret = 128 + WTERMSIG(child_status);
	}
	if (WIFEXITED(child_status))
	{
		info->ret = child_status;
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
	if ((pid = fork())== 0)
		child_process(info, cmd);
	else
		father_process(info, pid);
}