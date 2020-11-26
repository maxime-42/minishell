CC	= gcc

RM	= rm -f

NAME	= libft.a

MANDATORY =		./ft_memset.c\
				./ft_bzero.c\
				./ft_memcpy.c\
				./ft_memccpy.c\
				./ft_memchr.c\
				./ft_memcmp.c\
				./ft_memmove.c\
				./ft_strlen.c\
				./ft_isalpha.c\
				./ft_isdigit.c\
				./ft_isalnum.c\
				./ft_strnstr.c\
				./ft_strncmp.c\
				./ft_strlcpy.c\
				./ft_strlcat.c\
				./ft_atoi.c\
				./ft_strdup.c\
				./ft_calloc.c\
				./ft_substr.c\
				./ft_strjoin.c\
				./ft_strtrim.c\
				./ft_split.c\
				./ft_itoa.c\
				./ft_putchar_fd.c\
				./ft_putstr_fd.c\
				./ft_putendl_fd.c\
				./ft_putnbr_fd.c\
				./ft_strchr.c\
				./ft_isascii.c\
				./ft_isprint.c\
				./ft_strmapi.c\
				./ft_toupper.c\
				./ft_tolower.c\
				./ft_lenght_nbr.c\
				./ft_isspace.c\
				./ft_strcmp.c\
				./ft_strstr.c\
				./ft_strcpy.c\
				./ft_free_double_array.c\

BONUS	=	./ft_lstnew_bonus.c\
			./ft_lstadd_front_bonus.c\
			./ft_lstsize_bonus.c\
			./ft_lstlast_bonus.c\
			./ft_lstadd_back_bonus.c\
			./ft_lstdelone_bonus.c\
			./ft_lstclear_bonus.c\
			./ft_lstiter_bonus.c\
			./ft_lstmap_bonus.c\
			./ft_list_find_bonus.c\
			./ft_list_remove_if.c\
			./ft_list_remove_one_if.c\
			./ft_array_char.c\
			./ft_btree_clear.c\
			./ft_btree_del_one.c\
			./ft_btree_create_node.c\
			./ft_skip_white_space.c\
			./get_next_line.c\
			./get_next_line_utils.c\
			./ft_nb_character_in_word.c\
			./ft_btree_apply_suffix.c\
			./ft_free_double_array.c\
			./ft_strnew.c\
			./ft_memdel.c\
			./ft_strdel.c\
			./ft_free_string.c\
			./ft_remove_front.c\
			./ft_list_remove_current_node.c\
			./ft_is_even.c\
			./ft_get_size_array.c\
			./ft_nb_line_array.c\
			./ft_double_array_iter.c\
			./ft_sorted_list_insert.c\
			./ft_btree_insert_data.c\
			./ft_strndup.c\
			./ft_strchr.c\
			./ft_btree_dfs.c\
			./ft_init_tab.c\
			./ft_strrchr.c\

MANDATORY_SRCS	=	${MANDATORY}

BONUS_SRCS	=	${BONUS}

MANDATORY_OBJS	= ${MANDATORY_SRCS:.c=.o}

BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

CFLAGS	= -g -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${MANDATORY_OBJS}
			ar rc ${NAME} ${MANDATORY_OBJS}
			ranlib ${NAME}

all: ${NAME}

bonus:	${BONUS_OBJS} ${NAME}
			ar rc ${NAME} ${MANDATORY_OBJS} ${BONUS_OBJS}
			ranlib ${NAME}
clean:
	${RM} ${BONUS_OBJS} ${MANDATORY_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
