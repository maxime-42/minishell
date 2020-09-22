#include "minishell.h"

void    print_env(void *content)
{
    char    *var_env;

    var_env = (char *)content;
    if (ft_strchr(var_env, '='))
    {
        ft_putstr_fd(var_env, 1);
    }
}

void    my_env(char **cmd)
{
    if (!g_info.list_env)
        return ;
    ft_lstiter(g_info.list_env, print_env);
}