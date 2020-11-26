/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program_with_execve.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:45:38 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/26 17:53:22 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void			child_process(t_info *info, char **cmd)
{
	int			ret;
	char		*str;
	// char		*msg;
	// char		*msg_to_print;

	ret = execve(cmd[0], cmd, info->tab_var_env);
	if (ret == ERROR)
	{
	// 	printf("wshh\n");
	// 	msg = strerror(errno);
	// 	msg_to_print = ft_strjoin(": ", msg);
	// 	// error_msg("minishell: ", cmd[0], msg_to_print);
	// 	error_msg("minishell: ", "quell by ", "igoooo\n");
	// 	ft_putstr_fd("\n", 2);
	// 	ft_strdel(&msg_to_print);
		str = ft_strrchr(cmd[0], '/');
		if (str)
			error_msg("minishell: ", str + 1, ": command not found\n");
		else
			error_msg("minishell: ", cmd[0], ": command not found\n");
		
	}
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

	bool = true;
	update_tab_var_env(info->list_env);
	get_absolut_path(cmd);
	// print_tab(cmd);
	bool = check_permission(cmd[0]);
	if (bool == false)
		return ;
	if ((pid = fork()) == 0)
	{
		// signal(SIGQUIT, SIG_DFL);
		child_process(info, cmd);
	}
	else
	{
		father_process(info, pid);
	}
	(void)bool;
}
