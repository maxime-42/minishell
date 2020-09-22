#include "minishell.h"

void    my_echo(char **cmd)
{
    int index;
    int new_line;

    index = 1;
    if (!(new_line = ft_strcmp(cmd[1], "-n")))
        index = 2;
    while (cmd[index])
    {
        ft_putstr_fd(cmd[index], 1);
        index++;
    }
    if (new_line)
        ft_putstr_fd("\n", 1);    
}