/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_input_in_list_token.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:22:18 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/10 16:55:14 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  int        clear(t_list **begin)
{
        ft_lstclear(begin, &clear_token);
        return (ERROR);
}
/*
** le but et de cette fonction consiste a stranformer un string a un liste de token
** etape 1:
**  dans cette fonction je met chaque charactere de l'input dans une string =>token_value
**etape 2:
**  ensuite je definie le type de cette string 'token_value' avec la fonction get_type
**etape 3:
**  ensuite je crée un token avec les attribue des etapes precedent 1 et 2
**etape 4:
**  puis le token et mis dans un maillot puis un push addback
*/

static  const t_token   array_token[] =
  {
    {"&&", and},
    {"||", or},
    {"|", pipee},
    {"<", redir_left},
    {">", redir_right},
    {"<<", double_redir_left},
    {">>", redir_right},
    {";", semicolon},
    {"-", option_command},
    {"--", option_command},
    {"\"", double_quote},
    {"'", single_quote},
    {"\\", backslash},
    {"\f", space},
    {"\n", space},
    {"\r", space},
    {"\t", space},
    {"\v", space},
    {" ", space},
    {"$", variable},
    {0, 0},
  };

t_bool  is_operator(t_token_type type)
{

    if ((type >= 0 && type < NB_OPERATOR))
        return (true);
    return (false);
}

t_token_type    define_type_of_token(char *value)
{
    int         i;
    int         size;
    // static  unsigned int is_command = 0;

    i = 0;
    // if (++is_command == 1)
    
    //     return (command);
   
    while (array_token[i].value)
    {
        size = ft_strlen(array_token[i].value);
        if (!ft_memcmp(array_token[i].value, value, size))
        {
            // if (is_operator(array_token[i].type) == true)
                // is_command = 0;
            // printf("array_token[i].value : [%s]\n", (char *)array_token[i].value);
            // printf("array_token[i].type : [%d]\n", (int)array_token[i].type);
            return (array_token[i].type);
        }
        // printf("i : [%d]\n", i);
        i++;
    }
    return (literal);
}


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
            exit(clear(&begin));
        token_value[0] = input[index_input];
        if (!(token = factor(token_value, define_type_of_token(token_value))))
            exit(clear(&begin));
        if (!(new = ft_lstnew(token)))
            exit(clear(&begin));
        ft_lstadd_back(&begin, new);
    }
    return (begin);
}