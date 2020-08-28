#ifndef MINISHELL_H
# define MINISHELL_H
# define ERROR  -1
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "struct.h"

t_token_type        get_type_token(char *value);
t_btree             *expr(char **line);
int                 free_all(t_info *info, int code_return);
void                create_ast(t_btree **root, t_token *token);
void    print_token(void *ptr);
void                clear_token(void *content);
void    print_tab(char **array);

#endif
