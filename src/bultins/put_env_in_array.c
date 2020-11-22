/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_env_in_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:22:12 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/21 21:25:55 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			put_env_in_array(t_list *list_var_env)
{
	int			nb_line_array;

	if (!list_var_env)
		return ;
	nb_line_array = ft_lstsize(list_var_env);
	ft_array_char(nb_line_array, 0);
}
