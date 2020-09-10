/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_backslashe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:12:07 by mkayumba          #+#    #+#             */
/*   Updated: 2020/09/09 20:21:59 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**dans ce fichier je traite les cas suivant:
**  nombre de backslashe paire :
**                              on interprete la variable
**  nombre de backslashe impaire :
**                              on ont n'interpreter pas la variable
*/

/*
** etape 1:
**      counter les nombres des backslashe
** etape 2:
**      supprimer tous les backslashe 
**      ainsi que le dollors si c'est present
**  etape 3:
**      si le nombre des backslashes sont impaire 
**      le token suivant est transformer en literal
**      et je concaterner tous les literale ensemble
**  etape 4:
**      si le nombre des backslashes sont paire 
**          et si le premiere token est de type variable 
**          c'est à dire il faut interpreter la variable.
**      sinon il faut concatener tous les literale
            ça consiste a transforme le premiere token en literale
            ensuite concater tous les literale
**  etape 5:
**      remettre les backslashe 
*/

static  int     count_nb_backslashe(t_list *list)
{
    t_token     *token;
    int         nb_backslashe;
    
    nb_backslashe = 0;
    token = (t_token *)list->content;
    while (list && token->type == backslash)
    {
        if ((nb_backslashe % 2))
            token->type = literal;
        nb_backslashe += 1;
        if ((list = list->next))
            token = (t_token *)list->content;
    }
    if (!list && (nb_backslashe % 2))
    {
        ft_putstr_fd("error:\narguments are missing\n", 1);
        exit(free_all(&g_info, ERROR));
    }
    return (nb_backslashe);
}

static  void    remove_backslashe(t_list **begin, int nb_backslashe)
{
    int         i;

    i = 0;
    while (i < nb_backslashe)
    {
        ft_remove_front(begin, &clear_token);
        i++;
    }
}

static  void    push_back_token(t_list **begin, char *data, t_token_type type, int nb_duplication)
{
    t_token     *token;
    t_list      *node_to_add;
    char        *token_value;
    int         i;

    i = -1;
    while (++i < nb_duplication)
    {
        if (!(token_value = ft_strdup(data)))
            exit(free_all(&g_info, ERROR));
        if (!(token = create_token(token_value, type)))
                exit(free_all(&g_info, ERROR));
        node_to_add = ft_lstnew(token);
        ft_lstadd_front(begin, node_to_add);
    }
}

/*
**  le but de cette fonction et d'intrepter le token en 
**  fonction du token dans le maillot begin
**  si le token et de type variable j'interprete la variable
**  sinon je transforme le token qui est dans begin en lieteral puis
**  je concatener tous les literale 
*/

static  void    has_interpret(t_list **begin)
{
    t_token     *token;
    char        **array;
    char        *value_var;
    
    token = (t_token *)(*begin)->content;
    if (token->type == variable)
    {
        ft_remove_front(begin, &clear_token);
        concate_token_same_type(begin, literal);
        token = (*begin)->content;
        array = token->value;
        value_var = duplique_value_variable(g_info.list_env, array[0]);
        free(array[0]);
        array[0] = value_var;
    }
    else
    {
        change_type_of_token(begin, literal);
        concate_token_same_type(begin, literal);
    }
}

void            interpret_backslashe(t_list **begin)
{
    int         nb_backslashe;
    t_token     *token;

    token = (t_list *)(*begin);
    if (token->type != backslash)
        return ;
    nb_backslashe = count_nb_backslashe(*begin);
    remove_backslashe(begin, nb_backslashe);
    if (!*begin)
        ;
    else if ((nb_backslashe % 2))
    {
        change_type_of_token(begin, literal);
        concate_token_same_type(begin, literal);
    }
    else
        has_interpret(begin);
    push_back_token(begin, "\\", literal, (nb_backslashe / 2));
    concate_token_same_type(begin, literal);
}