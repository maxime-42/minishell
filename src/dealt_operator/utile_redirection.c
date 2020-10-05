/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:32:36 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/01 15:52:19 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char				*get_file_name(t_list **stack)
{
	t_token			*token;
	char			**file_name;
	t_list			*to_del;

	token = (*stack)->content;
	file_name = (char **)token->value;
	to_del = *stack;
	*stack = to_del->next;
	ft_lstdelone(to_del, &free_nothing);
	return (file_name[0]);
}

t_token				*get_command(t_list **stack)
{
	t_token			*token;
	t_list			*to_del;

	token = (*stack)->content;
	to_del = *stack;
	*stack = to_del->next;
	ft_lstdelone(to_del, &free_nothing);
	return (token);
}