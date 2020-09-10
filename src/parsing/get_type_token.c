/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:01:22 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/08 12:20:39 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_token_type    get_type_token(char *value)
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