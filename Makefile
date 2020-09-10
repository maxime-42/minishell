
RM	= rm -f

CC = gcc -g -Wall -Wextra -Werror -I./include/

NAME= minishell

SRC	=	./src/main.c\
		./src/utile/free_all.c\
		./src/parsing/expr.c\
		./src/parsing/init_env.c\
		./src/parsing/utile_parsing_input.c\
		./src/parsing/get_value_of_variable_env.c\
		./src/parsing/transform_input_in_list_token.c\
		./src/parsing/concate_token.c\
		./src/parsing/duplique_value_variable.c\
		./src/parsing/interpret_backslashe.c\
		./src/parsing/create_token.c\
		./src/parsing/change_type_of_token.c\
		./src/parsing/interpret_variable.c\
		./src/parsing/get_type_of_token.c\
		./src/parsing/interpret_input.c\

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
