#include "libft.h"

char		*ft_strndup(const char *s1, int n)
{
	char	*dup;
	int		i;
    int     size_s1;

	i = 0;
    size_s1 = (int)ft_strlen(s1);
    if ((n > size_s1))
        n = size_s1;
    if (!((dup = ft_strnew(n + 1))))
		return (0);
	while (i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
