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
char				*get_value_of_variable_env(t_list *list_env, char *name);
void				concate_token_same_type(t_list **begin, t_token_type type);
t_bool				is_operator(t_token_type type);
void				change_type_of_token(t_list **begin, t_token_type new_type);
char				*duplique_value_variable(t_list *list_env, char *variable_name);
void				test_free(void *ptr);
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
void				print_file(int fd);
void                free_nothing(void *ptr);
void				exec_cmd(t_info *info, t_btree *root);
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
void				dealt_exec_cmd(t_btree *root);
void				dealt_multiples_redirections(t_list *list);
t_bool				is_right_side_redirection(t_token_type type);
void				*get_token_value(t_token *token);
void				redirections(t_btree *root);
void				promp();
void				the_pipelines(t_btree *root, int count, int backup_fd);
void				parsing_input();
void				swap_token(t_token *a, t_token *b);
void				handle_signale_ctrl_c(int sig);
void				handle_signale_quit(int sig);
int					correction_syntaxe_operator(t_token *token);
int					dealt_quote(t_list **begin);
int					iter_list_1(t_list **begin);
int					iter_list_2(t_list *tmp);
void				btree_of_cmd();
int					interpret_variable(t_list **current);
void				str_whithout_many_space(t_token *token);
void				error_msg(char *cmd_name, char *arg, char *msg);
void				interpret_backslashe(t_list **list, t_bool in_quote);
void				print_tab(char **tab);
int					check_if_var_exist(char *s1, char *s2);

#endif
