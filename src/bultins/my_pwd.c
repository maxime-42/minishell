#include "minishell.h"
#include <errno.h>

static	void	error_(char *path)
{
	ft_putstr_fd("bash: ", 1);
	ft_putstr_fd("pwd: ", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(": ", 1);
    ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
	g_info.ret = 1;
}

void            my_pwd(char **cmd)
{
    char        *current_path;

    if (ft_nb_line_array(cmd) == 1)
    {
       	if (!(current_path = getcwd((char *)NULL, 0)))
            error_(cmd[0]);
        else
        {
            ft_putstr_fd(current_path, 1);
            ft_free_string(current_path);
            g_info.ret = 0;
        }
    }
    else
    {
       	ft_putstr_fd("bash: ", 1);
        ft_putstr_fd("too many agument\n", 1);
        g_info.ret = 0;
    }  
}