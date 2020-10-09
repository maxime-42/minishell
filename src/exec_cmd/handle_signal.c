#include "minishell.h"
//char    buf[100];
void	handle_sigint(int sig)
{
	g_info.ret = 130;
	if (!g_info.root)
	{
		free_all(&g_info, ERROR);
		exit(g_info.ret);
	}
    //read(0, buf, 100);
	(void)sig;
}