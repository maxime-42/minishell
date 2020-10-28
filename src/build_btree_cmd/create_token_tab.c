#include "minishell.h"

t_token		*create_tab(int *nb_case)
{
	int		size;
	t_token	*tab;

	size = *nb_case * 2;
	size += 1;
	tab = malloc(sizeof(t_token *) * (size + 1)); 
	if (!tab)
	{
		ft_putstr_fd("malloc failure\n", 1);
		exit(free_all(&g_info, ERROR));
	}
	return (tab);
}

void		init_tab(t_info *info)
{
	int		index_tab;
	
	index_tab = -1;
	info->tab = create_tab(&info->size_tab);
	while (++index_tab < info->size_tab)
	{
		info->tab[index_tab].value = NULL;
	}
}