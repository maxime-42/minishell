/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_backslashe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:59:40 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/17 18:45:38 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**dans ce fichier je traite les cas suivant:
**  nombre de backslashe paire :
**							  on interprete la variable
**  nombre de backslashe impaire :
**							  on ont n'interpreter pas la variable
** etape 1:
**	  counter les nombres des backslashe
** etape 2:
**	  supprimer tous les backslashe
**	  ainsi que le dollors si c'est present
**  etape 3:
**	  si le nombre des backslashes sont impaire
**	  le token suivant est transformer en literal
**	  et je concaterner tous les literale ensemble
**  etape 4:
**	  si le nombre des backslashes sont paire
**		  et si le premiere token est de type variable
**		  c'est à dire il faut interpreter la variable.
**	  sinon il faut concatener tous les literale
**		  ça consiste a transforme le premiere token en literale
**		  ensuite concater tous les literale
**  etape 5:
**	  remettre les backslashe
*/

void				change_the_next_type_in_literal
	(t_list **begin, t_token_type new_type)
{
	t_list			*tmp;
	t_token			*token;
	t_token_type	native_type;

	if (!*begin)
		return ;
	tmp = *begin;
	token = tmp->content;
	native_type = token->type;
	while (tmp)
	{
		token = tmp->content;
		if (token->type != native_type)
			return ;
		change_type_of_token(&tmp, new_type);
		tmp = tmp->next;
	}
}

static int			count_nb_backslashe(t_list *list)
{
	t_token			*token;
	int				nb_backslashe;

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

static t_list		*ptr_start(t_list **current, int nb_dereference)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = *current;
	while (i < nb_dereference)
	{
		change_type_of_token(&tmp, literal);
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		concate_token_same_type(current, literal);
	return (tmp);
}

void				delete_useless_backslashe(t_list **current,
					int nb_backslashe)
{
	int				nb_del;
	t_list			*to_del;

	nb_del = nb_backslashe / 2;
	if ((nb_backslashe % 2))
	{
		nb_del += 1;
	}
	nb_backslashe = nb_backslashe - nb_del;
	while (nb_del > 0)
	{
		to_del = *current;
		(*current) = to_del->next;
		ft_list_remove_current_node(&g_info.list_input, to_del, &clear_token);
		nb_del -= 1;
	}
}

void				interpret_backslashe(t_list **begin)
{
	int				nb_backslashe;
	t_token_type	type;
	t_list			*ptr_to_start;

	if (get_token_type((*begin)->content) != backslash)
		return ;
	nb_backslashe = count_nb_backslashe(*begin);
	delete_useless_backslashe(begin, nb_backslashe);
	if (!(ptr_to_start = ptr_start(begin, nb_backslashe / 2)))
		return ;
	type = get_token_type(ptr_to_start->content);
	if ((nb_backslashe % 2))
		change_type_of_token(&ptr_to_start, literal);
	else
	{
		if (type == variable)
			interpret_variable(&ptr_to_start);
		else
		{
			print_token(ptr_to_start->content);
			change_the_next_type_in_literal(&ptr_to_start, literal);
		}
	}
	concate_token_same_type(begin, literal);
}
