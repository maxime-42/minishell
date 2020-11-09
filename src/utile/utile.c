#include "minishell.h"

void    print_token_tab(void *ptr)
{
    t_token *token;
    char    **array;
	int		i;

	i = 0;
	if (!ptr)
	{
		printf("NULL print_token_tab\n");
		return ;
	}
    token = (t_token *)ptr;
    array = (char **)token->value;
	while (array[i])
	{
		printf("[%d] -> [%s]\n", i, array[i]);
		// ft_putstr_fd(array[i], 1);
		// ft_putstr_fd("\n", 1);
		i++;
	}
}

void    print_token(void *ptr)
{
    t_token *token;
    char    *array;

	if (!ptr)
		return ;
    token = (t_token *)ptr;
    array = (char *)token->value;
	// printf("[%s] ", array);

	printf("[%s] type: [%d]\n", array, token->type);
}



void        print_str(void *ptr)
{
    char    *array;
    
    array = (char *)ptr;
    printf("[%s] ", array);
}

void		print_file(int fd)
{
	char	*line;
	int		r;

	r = 1;
	line = 0;
	printf("got to the file\n");
	while (r != 0)
	{
		r = get_next_line(fd, &line);
		printf("[%s]\n", line);
		ft_free_string(line);
	}
	
}