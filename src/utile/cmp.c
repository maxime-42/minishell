int		cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	// return ((s1[i] == '=' || !s1[i]) ? 0 : 1);
	return ((s2[i] == '=' || !s2[i]) ? 0 : 1);
}