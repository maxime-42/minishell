/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:29:06 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/04 11:53:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "minishell.h"
/*
**  fonction factor:
**      la fonction factor créer un token et l'initialiser 
**      le token est initialiser avec les variable qui sont passer en parametre
*/
static  t_token     *factor(char *token_value, t_token_type token_type)
{
    t_token         *token;
    char            **array;

    if (!(token = malloc(sizeof(t_token))))
        exit(free_all(&g_info, ERROR));
    if (!(token->value = (void *)malloc(sizeof(char *) * (2))))
        return (0);
    array = (char **)token->value;
    array[0] = token_value;
    array[1] = 0;
    token->type = token_type;
    return (token);
}

void        clear(t_list **begin, t_bool is_token)
{
    if (is_token == true)
        ft_lstclear(begin, &clear_token);
    else
        ft_lstclear(begin, &ft_free_string);
    exit (ERROR);
}


/*
** fonction term:
**     la fonction terme permet de trouver : 
**          -la valeur du token
**          -le type du token
**      un token est delimiter par des espaces exemple : 
**      ls -l ici on a deux token ls et -l
**      chaque appel de cette fonction retourne un token 
*/ 
t_token             *term(t_list **begin)
{
    char            *token_value;
    t_token_type    token_type;
    int             size_value;
    t_token         *token;

    token = 0;
    delete_space(begin);
   /*  if (*line && **line)
    {
        size_value = ft_nb_character_in_word(line[0]);
        token_value = ft_strnew(size_value + 1);
        token_value = ft_memcpy(token_value, *line, size_value);
        token_type = get_type_token(token_value);
        if (!(token = factor(token_value, token_type)))
            exit(free_all(&g_info, ERROR));
        *line += size_value;
    }  */
    (void)token;
    (void)token_type;
    (void)size_value;
    (void)token;
    (void)token_value;
    (void)begin;
     return (token);
} 

/*
** inside node root the attribute "root->content" it is pointer of token
** à l'intérieur de token->value se trouve une liste chainee avec
**  c'est  commande et option etc...
*/
t_list              *transform_input_in_list_token(char *input)
{
    t_list          *begin;
    t_list          *new;
    int             index_input;
    char            *token_value;
    t_token         *token;
    
    begin = 0;
    index_input = -1;
    while (input[++index_input])
    {
        if (!(token_value = ft_strnew(2)))
            clear(&begin, false);
        ft_memcpy((void *)token_value, (void *)(input + index_input), 1);
        if (!(token = factor(token_value, get_type_token(token_value))))
            clear(&begin, true);
        if (!(new = ft_lstnew(token)))
            clear(&begin, true);
        ft_lstadd_back(&begin, new);
    }
    return (begin);
}

t_btree             *expr(char *line)
{
    t_btree         *root;
    t_token         *token;
    t_list          *input;

    root = 0;
    input = transform_input_in_list_token(line);
    delete_space(&input);
    g_info.generic_ptr = input;
    return (0);
  /*   while (input_token)
    {
        //printf("line:%s\n", *line);
        if ((token = term(input_token)))
        {
            create_ast(&root, token);
            g_info.root = (void *)root;
        }
        else
            return (root);
    } */
    (void)token;
    (void)input;
    (void)root;
    (void)input;
    return (root);
}