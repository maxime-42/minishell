/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:26:53 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/05 13:05:29 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			parsing_input()
{
	t_list		*input;

	input = g_info.list_input;
	interpret_input(&input);
	if ((g_info.status & (FLAGS_DOUBLE_QUOTE)))
	{
		ft_putstr_fd("minishell: missing quote\n", 1);
		ft_lstclear(&g_info.list_input, &clear_token);
	}
	else if ((g_info.status & (FLAGS_SINGLE_QUOTE)))
	{
		ft_putstr_fd("minishell: missing quote\n", 1);
		ft_lstclear(&g_info.list_input, &clear_token);
	}
	special_case_redirection(g_info.list_input);
	(void)input;
}