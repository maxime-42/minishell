/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:54:21 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/27 15:23:26 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <ctype.h>
# define STOP 0
# define CONTINUE 1

typedef enum		e_bool
{
	false,
	true,
}					t_bool;

typedef struct		s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	void			*content;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strnstr(const char *big, const char
					*little, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_atoi(const char *nptr);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char *s, char *str);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s1);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strchr(const char *s, int c);
int					ft_isascii(int c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					lenght_nbr(int nb);
int					get_next_line(int fd, char **line);
int					ft_isspace (int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strcpy(char *dest, char *src);
int					ft_nb_character_in_word(char *word);
int					ft_skip_white_space(char *str);
char				**ft_copy_double_array(char **dest, char **src);
char				**ft_array_char(int line, int column);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_free_string(void *ptr);
void				ft_free_double_array(void *ptr);
t_bool				ft_is_even(int n);
void				ft_get_size_array(char **array, int *line, int *column);
int					ft_nb_line_array(char **array);
int					ft_str_count_ncharacter(char *str, char n);
char				*ft_strndup(const char *s1, int n);
char				*strrchr(const char *s, int c);
void				ft_init_tab(char **tab, int nb_line);
void				ft_list_iteration(t_list *lst, int (*f)());
void				ft_dlst_del_one(t_list *lst, void (*del)(void *));
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *));
void				ft_list_remove_one_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *));
void				ft_btree_clear(t_btree *root, void (*del)(void *));
void				ft_btree_del_one(t_btree *root, void (*del)(void *));
t_btree				*ft_btree_create_node(void *item);
void				ft_btree_apply_suffix(t_btree *root,
					void (*applyf)(void *));
void				ft_test(t_btree *root, void (*applyf)(void *));
void				ft_remove_front(t_list **begin, void (*free_fct)(void *));
void				ft_list_remove_current_node(t_list **begin_list,
					t_list *to_del, void (*free_fct)(void *));
t_list				*ft_list_find(t_list *begin_list, void *data_ref,
					int (*cmp)());
void				ft_sorted_list_insert(t_list **begin_list,
					void *data, int (*cmp)());
void				ft_btree_insert_data(t_btree **root, void *item,
					int (*cmpf)());
void				ft_btree_dfs_inorder(t_btree *root,
					void (*ptr_function)());
void				ft_double_array_iter(char **array, void (*fct)());
char				*ft_strrchr(char *s, int c);
#endif
