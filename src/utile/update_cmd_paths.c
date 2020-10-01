#include "minishell.h"

static      char    *extract_path(char *value, char **path)
{
    int     size;
    char    *ptr;

    if ((ptr = ft_strchr(value, ':')))
    {
        size = ptr - value;
        ptr++;
    }
    else
    {
        size = ft_strlen(value);
        ptr = value + size;
    }
    if (!(path[0] = ft_strnew(size + 3)))
    {
        ft_putstr_fd("malloc failure", 1);
        exit(free_all(&g_info, ERROR));
    }
    ft_memcpy(path[0], value, size);
    path[0][size] = '/';
    return (ptr);
}

void            update_cmd_path(t_info *info)
{
    char    *value;
    char    *path;
    t_list  *new;

    if (!info->list_env)
        return ;
    ft_lstclear(&info->list_path, ft_free_string);
    info->list_path = 0;
    value = get_value_of_variable_env(info->list_env, "PATH");
    while (*value)
    {

        value = extract_path(value, &path);
        if (!(new = ft_lstnew(path)))
        {
            ft_putstr_fd("malloc failure", 1);
            exit(free_all(info, ERROR));
        }
        ft_lstadd_back(&info->list_path, new);
    }
}