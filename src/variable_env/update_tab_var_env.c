#include "minishell.h"

void        update_tab_var_env(t_list *list_env)
{
    int     nline;

    if (!list_env)
        return ;
    if (g_info.tab_var_env)
    {
        free(g_info.tab_var_env);
        g_info.tab_var_env = 0;
    }
    nline = ft_lstsize(list_env);
    if (!(g_info.tab_var_env = malloc(sizeof(char *) * (nline + 1))))
    {
        ft_putstr_fd("error:\nmalloc failure\n", 1);
        exit(free_all(&g_info, ERROR));
    }
    nline = -1;
    while (list_env)
    {
        g_info.tab_var_env[++nline] = (char *)list_env->content;
        list_env = list_env->next;
    }
    g_info.tab_var_env[nline] = 0;
}