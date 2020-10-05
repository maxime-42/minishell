#include "minishell.h"

t_token_type	g_tab_operator[] = {
	simple_redir_left,
	simple_redir_right,
	or,
	pipeline,
	and,
};

static		check_type_operateur(t_token_type type)
{
	int		index_tab;

	index_tab = 0;
	while (index_tab < 5)
	{
		if (g_tab_operator[index_tab] == type)
			return (true);
		index_tab++;
	}
	return (false);
}

void		handle_operateur(t_info *info)
{
	t_list	*tmp;
	t_token	*token;

	tmp = info->list_input;
	while (tmp)
	{
		token = tmp->content;
		if (check_type_operateur(token->type) == true)
		{
			
		}
		tmp = tmp->next;
	}
	
}
