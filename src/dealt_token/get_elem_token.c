#include "minishell.h"

t_token_type	get_token_type(t_token *token)
{
	return (token->type);
}

char			**get_token_value(t_token *token)
{
	return (token->value);
}
