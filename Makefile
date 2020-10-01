
RM	= rm -f

CC = gcc -g -Wall -Wextra -Werror -I./include/

NAME= minishell

SRC	=	./src/main.c\
		./src/utile/free_all.c\
		./src/utile/update_tab_var_env.c\
		./src/utile/cmp.c\
		./src/utile/utile.c\
		./src/utile/update_cmd_paths.c\
		./src/parsing/parsing_input.c\
		./src/parsing/init_env.c\
		./src/parsing/utile_parsing_input.c\
		./src/parsing/get_value_of_variable_env.c\
		./src/parsing/transform_input_in_list_token.c\
		./src/parsing/concate_token.c\
		./src/parsing/duplique_value_variable.c\
		./src/parsing/get_type_of_token.c\
		./src/parsing/interpret_backslashe.c\
		./src/parsing/create_token.c\
		./src/parsing/change_type_of_token.c\
		./src/parsing/interpret_variable.c\
		./src/parsing/interpret_input.c\
		./src/parsing/dealt_quote.c\
		./src/bultins/my_setenv.c\
		./src/bultins/my_export.c\
		./src/bultins/my_unset.c\
		./src/bultins/my_pwd.c\
		./src/bultins/my_echo.c\
		./src/bultins/my_env.c\
		./src/bultins/my_cd.c\
		./src/bultins/my_exit.c\
		./src/exec_cmd_syst.c\
		./src/get_node_ancestor.c\
		./src/dealt_command_and_operator.c\
		./src/dealt_operator/pipeline.c\
		./src/travel_ast.c\
		./src/utile/get_type_node.c\

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
