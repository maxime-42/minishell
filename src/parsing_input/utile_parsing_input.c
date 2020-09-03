/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_parsing_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:32:09 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/03 17:06:20 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// ('\f'), newline ('\n'), carriage return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').
 
 int               cmp(void *content, void *data_ref)
 {
     t_token        *token;
    char            **array;

    token = (t_token *)content;
    array = token->value;
    return (ft_strcmp(array[0], (char *)data_ref));
 }
 
 void   delete_space(t_list **begin)
 {
    char    *ispace[7];
    int     index_ispace;

    index_ispace = 0;
    ispace[0] = "\f";
    ispace[1] = "\n";
    ispace[2] = "\r";
    ispace[3] = "\t";
    ispace[4] = "\v";
    ispace[5] = " ";
    ispace[6] = 0;
    while (ispace[index_ispace])
    {
        printf("index %d:[%s]\n", index_ispace, ispace[index_ispace]);
        ft_list_remove_if(begin, ispace[index_ispace], &cmp, clear_token);
        index_ispace++;
    }
 }

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
    {"-", shortcut_option},
    {"--", long_option},
    {"\"", double_quote},
    {"'", single_quote},
    {"\\", backslash},
    {0, 0},
  };

static  t_bool  is_operator(t_token_type type)
{

    if ((type >= 0 && type < NB_OPERATOR))
        return (true);
    return (false);
}

t_token_type    get_type_token(char *value)
{
    int         i;
    int         size;
    static  unsigned int is_command = 0;

    i = 0;
    if (++is_command == 1)
        return (command);
    while (array_token[i].value)
    {
        size = ft_strlen(array_token[i].value);
        if (!ft_memcmp(array_token[i].value, value, size))
        {
            if (is_operator(array_token[i].type) == true)
                is_command = 0;
            return (array_token[i].type);
        }
        i++;
    }
    return (literale);
}

void     get_size_double_array(char **array, int *line, int *column)
{
    int i;
    int j;

    i = 0;
    while (array[i])
    {
        j = (int) ft_strlen(array[i]);
        if (j > *column)
            *column = j;
        i++;
    }
    *line = i;
}


/*
** fonction init_node:
** cette fonction créer et initialiser un node:
**      node->content = token 
**      sachant que:
**      token->value    :   liste chainée d'une commande
**      token->type     :   le type de token
*/

static  void    init_node(t_btree **node, t_token *token)
{
    if (!(*node = ft_btree_create_node(token)))
        exit(free_all(&g_info, ERROR));
}
void    toto(void *test)
{
    (void)test;
}
static  void    update_array_command_node(t_btree **root, t_token *new_token)
{
    t_token     *root_token;
    char        **new_array;
    int         line;
    int         column;
    char        **tmp;
    
    line = 0;
    column = 0;
    root_token = (t_token *)((*root)->content);
   
    get_size_double_array(root_token->value, &line, &column);
    line += 1;
   
    new_array = ft_array_char(line , column);

    tmp = (char **)new_token->value;
    ft_copy_double_array(new_array, root_token->value);
    ft_strcpy(new_array[line - 1], tmp[0]);

    //ft_free_double_array(new_array);

    ft_free_double_array(root_token->value);

    ft_free_double_array(new_token->value);
    
    free(new_token);
    root_token->value = new_array;
    //ft_free_double_array(root_token->value);
    
    //clear_token(root_token);
    
    //exit(0);
    
    //clear_token(new_token);
   // ft_btree_apply_suffix(*root, &print_token);
    // ft_btree_clear(*root, &clear_token);
    // exit(0);
}

void            create_ast(t_btree **root, t_token *token)
{
    t_btree     *node;
    t_token     *root_token;

    node = 0;
    if (!(*root))
    {
        init_node(root, token);
    }
    else if (is_operator(token->type) == true)
    {
        init_node(&node, token);
        node->left = *root;
        *root = node;
    }
    else
    {
        root_token = (*root)->content;
        if (is_operator(root_token->type) == true)
        {
            if (!(*root)->right)
                init_node(&(*root)->right, token);
            else
                update_array_command_node(&(*root)->right, token);
        }
        else
        {
            update_array_command_node(root, token);
        }
    }

}