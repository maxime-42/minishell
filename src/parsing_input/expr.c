/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:29:06 by mkayumba          #+#    #+#             */
/*   Updated: 2020/08/28 16:21:27 by mkayumba         ###   ########.fr       */
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
    if (!(token->value = (void *)malloc(sizeof(char *) * (1 + 1))))
        exit(free_all(&g_info, ERROR));
    array = (char **)token->value;
    array[0] = token_value;
    array[1] = 0;
    // token->value = &array;
    token->type = token_type;
    return (token);
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

t_token             *term(char **line)
{
    char            *token_value;
    t_token_type    token_type;
    int             size_value;
    t_token         *token;

    token = 0;
    (*line) += ft_skip_white_space(*line);
    if (*line && **line)
    {
        size_value = ft_nb_character_in_word(line[0]);
        token_value = ft_strnew(size_value + 1);
        token_value = ft_memcpy(token_value, *line, size_value);
        token_type = get_type_token(token_value);
        token = factor(token_value, token_type);
        *line += size_value;
    }
     return (token);
} 

/*
** inside node root the attribute "root->content" it is pointer of token
** à l'intérieur de token->value se trouve une liste chainee avec
**  c'est  commande et option etc...
*/

t_btree             *expr(char **line)
{
    t_btree         *root;
    t_token         *token;

    char            **array;
    root = 0;
    while (**line)
    {
        //printf("line:%s\n", *line);
        if ((token = term(line)))
        {
            create_ast(&root, token);
        }
        else
            return (root);
        if (**line && **line + 1)
            (*line)++;
    }
    (void)array;
    return (root);
}