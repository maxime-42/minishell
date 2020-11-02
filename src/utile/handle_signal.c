/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:07:34 by mkayumba          #+#    #+#             */
/*   Updated: 2020/10/19 14:02:19 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sig_int(int sig)
{
	g_info.ret = 130;
	ft_putstr_fd("\n>", 0);
	(void)sig;
}

void	handle_sig_quit(int sig)
{
	g_info.ret = 131;
	ft_putstr_fd("\n>", 0);
	(void)sig;
}