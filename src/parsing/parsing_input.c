/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:26:53 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/27 16:41:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			parsing_input(char *str_input)
{
	t_list		*input;

	tokenizer(str_input);
	input = g_info.list_input;
	interpret_input(&input);
	// ft_lstiter(g_info.list_input, &print_token);
	if (g_info.status != 0)
	{
		ft_putstr_fd("ERROR syntaxe QUOTE\n", 1);
		exit(free_all(&g_info, ERROR));
	}
	// special_case_redirection(g_info.list_input);
	(void)input;
}