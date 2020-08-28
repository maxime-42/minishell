
RM	= rm -f

CC = gcc -g -Wall -Wextra -Werror -I./include/

NAME= minishell

SRC	=	./src/main.c\
		./src/parsing_input/expr.c\
		./src/parsing_input/utile_parsing_input.c\
		./src/utile/free_all.c\
	

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
