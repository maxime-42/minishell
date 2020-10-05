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
    int     i;
    char    **array;

    i = 0;
	if (!ptr)
	{
		printf("[null]\n");
	}
    token = (t_token *)ptr;
    array = (char **)token->value;
	printf("type: [%d]", token->type);
    while (array && array[i])
    {
		// printf("value:[%s]\ttype: [%d]\n", array[i], token->type);
		printf("value:[%s]\n", array[i]);
        i++;
    }
    printf("\n");
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
    printf("[%s]\n", array);
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