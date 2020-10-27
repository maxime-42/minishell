#include "minishell.h"

void	dfs_inorder(t_btree *root)
{
	if (!root)
		return ;
    char    *str;
    str = root->content;
	dfs_inorder(root->left);
	printf("%s ", str);
	dfs_inorder(root->right);
}


void    print_token(void *ptr)
{
    t_token *token;
    char    *array;

	if (!ptr)
		return ;
    token = (t_token *)ptr;
    array = (char *)token->value;
	printf("[%s] type: [%d]\n", array, token->type);
}

void        print_tab(void *ptr)
{
    char    **array;
    
    array = (char **)ptr;
    printf("[%s]\n", array[0]);
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