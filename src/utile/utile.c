/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:59:24 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/20 16:26:44 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		error_msg(char *cmd_name, char *arg, char *msg)
{
	ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
}

t_list				*skipt_space(t_list *list)
{
	t_token			*token;
	
	while (list)
	{
		token = list->content;
		if (token->type != space)
		{
			return (list);
		}
		list = list->next;
	}
	return (0);
}

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
		i++;
	}
}

void				print_tab(char **tab)
{
	int				i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		printf("tab => [%s]\n", tab[i++]);
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