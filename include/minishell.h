#ifndef MINISHELL_H
# define MINISHELL_H
# define ERROR  -1
# define SUCCESS 0
# define ERROR_BASH 127
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "struct.h"
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int					free_all(t_info *info, int code_return);
void				create_ast(t_btree **root, t_token *token);
void				print_token(void *ptr);
void				clear_token(void *content);
t_list				*init_env(char **env);
t_token				*factor(char *token_value, t_token_type token_type);
char				*get_value_of_variable_env(t_list *list_env, char *name);
t_list				*transform_input_in_list_token(char *input);
void				concate_token_same_type(t_list **begin, t_token_type type);
t_bool				is_operator(t_token_type type);
void				interpret_backslashe(t_list **begin);
t_token				*create_token(char *token_value, t_token_type token_type);
void				change_type_of_token(t_list **begin, t_token_type new_type);
char				*duplique_value_variable(t_list *list_env, char *variable_name);
t_token_type		get_type_of_token(t_list **current);
void				interpret_variable(t_list **current);
void				interpret_input(t_list **begin);
void				dealt_quote(t_list **begin);
void				test_free(void *ptr);
void				parsing_input(char *str_input);
void				my_setenv(char *name, char *value);
void				my_pwd(char **cmd);
int					cmp(char *s1, char *s2);
void				my_echo(char **cmd);
void				my_cd(char **cmd);
void				my_pwd(char **cmd);
void				my_export(char **cmd);
void				my_unset(char **cmd);
void				my_env(char **cmd);
void				my_exit(char **my_exit);
void				update_cmd_path(t_info *info);
void				update_tab_var_env(t_list *list_env);
pid_t				create_process(void);
void				exec_cmd_syst(t_info *info, char **cmd);
t_btree				*get_node_ancestor(t_btree *node);
void				dealt_command(t_token *token);
void				dealt_operator(t_btree **node);
void				my_pipeline(t_info *info);
void				travel_ast(t_btree *root);
void				print_file(int fd);
t_token_type		get_type_node(t_btree **node);
void                free_nothing(void *ptr);


#endif
