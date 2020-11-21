
RM	= rm -f

CC = gcc -g -Wall -Wextra -Werror -I./include/

NAME= minishell

SRC	=	./src/main.c\
		./src/parsing/utile_iter_list.c\
		./src/parsing/check_syntaxe_operator.c\
		./src/parsing/dealt_quote.c\
		./src/parsing/interpret_backslashe.c\
		./src/parsing/iter_list.c\
		./src/parsing/utile_backslash.c\
		./src/dealt_token/concate_token.c\
		./src/dealt_token/create_token.c\
		./src/dealt_token/get_elem_token.c\
		./src/dealt_token/handler_type_token.c\
		./src/dealt_token/tokenizer.c\
		./src/bultins/my_cd.c\
		./src/bultins/my_echo.c\
		./src/bultins/my_env.c\
		./src/bultins/my_exit.c\
		./src/bultins/my_export.c\
		./src/bultins/my_pwd.c\
		./src/bultins/my_setenv.c\
		./src/bultins/my_unset.c\
		./src/bultins/put_env_in_array.c\
		./src/dealt_seperator/redirections.c\
		./src/dealt_seperator/pipeline.c\
		./src/variable_env/duplique_value_variable.c\
		./src/variable_env/get_value_of_variable_env.c\
		./src/variable_env/init_env.c\
		./src/variable_env/str_without_many_space.c\
		./src/variable_env/interpret_variable.c\
		./src/variable_env/update_cmd_paths.c\
		./src/variable_env/update_tab_var_env.c\
		./src/exec/build_ast.c\
		./src/exec/dealt_exec_cmd.c\
		./src/exec/btree_of_cmd.c\
		./src/exec/exec_program_with_execve.c\
		./src/utile/free_all.c\
		./src/utile/handle_signal.c\
		./src/utile/utile.c\

OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	make bonus -C ./libft
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft 

clean	:
	make clean -C ./libft
	rm -f $(NAME) $(OBJ)

fclean:	clean
	make fclean -C ./libft
	$(RM) $(NAME)

re	: clean all
