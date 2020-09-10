/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:29:06 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/08 11:21:23 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "minishell.h"
/*
**  fonction factor:
**      la fonction factor créer un token et l'initialiser 
**      le token est initialiser avec les variable qui sont passer en parametre
*/
t_token     *factor(char *token_value, t_token_type token_type)
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


t_btree             *expr(char *str_input)
{
    t_btree         *root;
    t_token         *token;
    t_list          *list_input;

    root = 0;
  

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
    (void)list_input;
    (void)root;
    (void)str_input;
    return (root);
}