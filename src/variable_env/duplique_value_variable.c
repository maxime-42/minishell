/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplique_value_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:15:01 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/23 16:28:06 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*duplique_value_variable(t_list *list_env, char *variable_name)
{
	char	*value_var;
	char	*duplicate_value;

	if (list_env)
	{
		value_var = get_value_of_variable_env(list_env, variable_name);
		if (!value_var)
			return (0);
		else
		{
			duplicate_value = ft_strdup(value_var);
			if (!duplicate_value)
				exit(free_all(&g_info, ERROR));
		}
		return (duplicate_value);
	}
	return (0);
}