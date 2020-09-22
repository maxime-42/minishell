#include "libft.h"

int     ft_str_count_ncharacter(char *str, char n)
{ 
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == n)
            return (i);
        i++;
    }
    return (i);
}