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
void				print_token(void *ptr);
void				clear_token(void *content);
t_list				*init_env(char **env);
t_token				*factor(char *token_value, t_token_type token_type);
char				*get_value_of_variable_env(t_list *list_env, char *name);
void				concate_token_same_type(t_list **begin, t_token_type type);
t_bool				is_operator(t_token_type type);
void				interpret_backslashe(t_list **begin);
void				change_type_of_token(t_list **begin, t_token_type new_type);
char				*duplique_value_variable(t_list *list_env, char *variable_name);
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
void				dealt_operator(t_token_type type);
void				my_pipeline(t_info *info);
void				print_file(int fd);
void                free_nothing(void *ptr);
t_token				*get_command(t_list **stack);
char				*get_file_name(t_list **stack);
void				my_and(t_info *info);
void				my_or(t_info *info);
void				exec_cmd(t_info *info, t_btree *root);
void				my_semiconlon(t_info *info);
void				handle_sig_int(int sig);
void				handle_sig_quit(int sig);
void				special_case_redirection(t_list *current);
t_token_type		get_token_type(t_token *token);
void				print_str(void *ptr);
t_token				*create_token(void *token_value, t_token_type token_type);
void				handle_operator(t_list **current);
void				tokenizer(char *input);
void				check_quote_open_and_close(t_token_type type, t_info *info);
void				put_input_list_in_btree(t_btree **root, t_list *current);
t_bool				is_separator(t_token_type type);
void				btree_free_content(void *content);
void				print_token_tab(void *ptr);
void				build_ast(t_btree **btree_root, t_list **input);
void				btree_of_cmd(t_list *input);
void				dealt_exec_cmd(t_btree *root);
void				dealt_multiples_redirections(t_list *list);
t_bool				is_right_side_redirection(t_token_type type);
void				*get_token_value(t_token *token);
void				my_simple_redirection_right(t_btree *root);
void				my_double_redirection_right(t_btree *root);
void				check_syntaxe_operator(t_token *token);
void				my_simple_redirection_left(t_btree *root);
void				redirections(t_btree *root);

#endif
