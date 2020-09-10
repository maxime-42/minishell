#ifndef MINISHELL_H
# define MINISHELL_H
# define ERROR  -1
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "struct.h"
#include <unistd.h>

t_token_type        get_type_token(char *value);
t_btree             *expr(char *line);
int                 free_all(t_info *info, int code_return);
void                create_ast(t_btree **root, t_token *token);
void                print_token(void *ptr);
void                clear_token(void *content);
void                delete_space(t_list **begin);
t_list              *init_env(char **env);
t_token             *factor(char *token_value, t_token_type token_type);
char                *get_value_of_variable_env(t_list *list_env, char *name);
t_list              *transform_input_in_list_token(char *input);
void                concate_token_same_type(t_list **begin, t_token_type type);
t_bool              is_operator(t_token_type type);
void                interpret_backslashe(t_list **begin);
t_token             *create_token(char *token_value, t_token_type token_type);
void                change_type_of_token(t_list **begin, t_token_type new_type);
char                *duplique_value_variable(t_list *list_env, char *variable_name);

#endif
