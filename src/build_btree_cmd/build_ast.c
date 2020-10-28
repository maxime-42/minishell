#include "minishell.h"

void			create_ast(t_btree **root, t_list *input)
{
	t_token		*token;
	char		*join;

	join = 0;
	token = input->content;
	while (input && is_seperator(token->type) != true)
	{
		token = input->content;
		if (is_seperator(token->type) == space)
		{
			token = new_token(&join, token->type);
			push_left_or_right(root, token);
			//token = input->content;
			push_left_or_right(root, token);
		}
		else if (token->type != space)
			join = join_arg(join, token->value);
		input = input->next;
	}
}