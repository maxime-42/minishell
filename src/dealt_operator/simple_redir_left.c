#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

static void			error_(char *file_name)
{
	ft_putstr_fd("bash: ", 1);
	ft_putstr_fd(file_name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
	g_info.ret = ERROR_BASH;
}

void				my_simple_redirection_left(t_info *info)
{
	int				fd;
	t_token			*token;
	char			*file_name;

	if (!info->stack)
		return ;
	token = get_command(&info->stack);
	file_name = get_file_name(&info->stack);
	if ((fd = open(file_name, O_RDONLY)) == ERROR)
	{
		error_(file_name);
		return ;
	}
	if (fork() == 0)
	{
		dup2(fd, 0);
		close(fd);
		dealt_command(token);
		exit (info->ret);
	}
	wait(NULL);
}