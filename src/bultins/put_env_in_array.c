#include "minishell.h"

static  void    new_str(t_list *list_var_env, char **array_env)
{
    int         i;

    i = 0;
    while (list_var_env)
    {
        ft_free_string(array_env[i]);
        array_env[i] = strdup(list_var_env->content);
        list_var_env = list_var_env->next;
        i++;
    }
}

void            put_env_in_array(t_list *list_var_env)
{
    int         nb_line_array;

    if (!list_var_env)
        return ;
    nb_line_array = ft_lstsize(list_var_env);
    ft_array_char(nb_line_array, 0);
}