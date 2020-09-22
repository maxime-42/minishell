#include "libft.h"

char    *strrchr(const char *s, int c)
{
    int index_s;

    index_s = (int)ft_strlen(s);
    while (index_s >= 0)
    {
        if (s[index_s] == c)
            return (s + index_s);
        index_s++;
    }
    return (0);
}