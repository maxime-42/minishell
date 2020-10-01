
#include "minishell.h"

void    my_exit(char **cmd)
{
    free_all(&g_info, ERROR);
    exit(0);
    (void)cmd;
}