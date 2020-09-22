#include "minishell.h"

// int		unset_cmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] && s2[i] && s1[i] == s2[i])
// 	{
// 		i++;
// 	}
// 	// return ((!s2[i]) ? 0 : 1);
// 	return ((s1[i] == '=' || !s1[i]) ? 0 : 1);
// }

static  void    error_(char *str)
{
    ft_putstr_fd("bash: unset: «", 1);
    ft_putstr_fd(str, 1);
    ft_putstr_fd(" » : identifiant non valable\n", 1);
    g_info.ret = 1;
}
void        my_unset(char **cmd)
{
    t_list  *to_del;
    int     index;
    t_list  *begin;

    index = 0;
    begin = g_info.list_env;
    while (cmd[++index])
    {
        if (ft_strchr(cmd[index], '='))
            error_(cmd[index]);
        // else if ((to_del = ft_list_find(begin, cmd[index], unset_cmp)))
        else if ((to_del = ft_list_find(begin, cmd[index], cmp)))
        {
            ft_list_remove_current_node(&begin, to_del, ft_free_string);
            g_info.ret = 0;
        }
        else
            g_info.ret = 1;
    }
}