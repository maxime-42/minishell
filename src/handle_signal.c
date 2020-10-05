#include "minishell.h"

void	handle_sigint(int sig)
{
	g_info.ret = 130;
	if (!g_info.root)
	{
		free_all(&g_info, ERROR);
		exit(g_info.ret);
	}
	(void)sig;
}