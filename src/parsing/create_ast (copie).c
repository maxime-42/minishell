#include "minishell.h"

// static	void		init_node(t_btree **node, t_token *token)
// {
// 	if (!(*node = ft_btree_create_node(token)))
// 	{
// 		ft_btree_clear(g_info.root, &free_nothing);
// 		g_info.root = 0;
// 		ft_lstclear(&g_info.list_input, &clear_token);
// 		exit(free_all(&g_info, ERROR));
// 	}
// }

 t_token				*new_token(char **tab, t_token_type type)
{
	t_token			*token;

	if (!tab)
		return (0);
	if (!(token = malloc(sizeof(t_token))))
	{
		ft_free_double_array(tab);
		exit(free_all(&g_info, ERROR));
	}
	token->value = tab;
	token->type = type;
	return (token);
}

char				**fill_tab(t_list **stack)
{
	char			**tab;
	t_list			*to_del;
	int				index;

	index = -1;
	if (!*stack)
		return (0);
	if (!(tab = malloc(sizeof(char *) * (ft_lstsize(*stack) + 1))))
		exit(free_all(&g_info, ERROR));
	while (*stack)
	{
		tab[++index] = (char *)(*stack)->content;
		to_del = *stack;
		*stack = to_del->next;
		free(to_del);
	}
	tab[index] = 0;
	*stack = 0;
	return (tab);
}

void				fill_stack(t_list *current, t_list **stack)
{
	t_list			*new;
	char			**tab;
	char			*dup;

	tab = get_token_value(current->content);
	dup = ft_strdup(tab[0]);
	if (!dup)
		exit(free_all(&g_info, ERROR));
	new = ft_lstnew(dup);
	if (!new)
		exit(free_all(&g_info, ERROR));
	ft_lstadd_back(stack, new);
}

void			create_ast(t_btree **root, t_list *input, t_list **stack)
{
	t_token		*token;
	char		**tab;

	while (input)
	{
		token = input->content;
		if (is_operator(token->type) == true)
		{
			tab = fill_tab(stack);
			token = new_token(tab, token->type);
			print_token(token);
			clear_token(token);
			//push_left_or_reft(&g_info.root, token);
			fill_stack(input, stack);
			tab = fill_tab(stack);
			token = new_token(tab, token->type);
			print_token(token);
			clear_token(token);
			//push_left_or_reft(&g_info.root, token);
		}
		else if (token->type != space)
			fill_stack(input, stack);
		input = input->next;
	}
	if (stack)
	{
		tab = fill_tab(stack);
		token = new_token(tab, token->type);
		print_token(token);
		clear_token(token);
		//create_ast(&g_info.root, token);
	}
}                                                                                                                                                                         