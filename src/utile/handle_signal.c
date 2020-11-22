/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:07:34 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 22:23:54 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signale_ctrl_c(int sig)
{
	g_info.ret = 130;
	ft_lstclear(&g_info.list_input, &clear_token);
	ft_putstr_fd("\n->", 1);
	(void)sig;
}
