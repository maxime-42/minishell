/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:12:43 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/22 14:52:26 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			err_(char *str)
{
	error_msg("minishell: export: `", str, "': not a valid identifier\n");
	g_info.ret = ERROR_EXPORT;
}

/*
** the name of variable must be composed of alphabet
** name=value
*/

int					check_syntaxe(char *str)
{
	int				r;
	int				i;

	i = -1;
	if (str[0] == '=')
	{
		err_(str);
		return (ERROR);
	}
	while (str[++i] && str[i] != '=')
	{
		r = ft_isalnum(str[i]);
		if (r == 0 && str[i] != '_')
		{
			err_(str);
			return (ERROR);
		}
	}
	return (SUCCESS);
}
