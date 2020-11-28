/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <mkayumba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:10:36 by mkayumba          #+#    #+#             */
/*   Updated: 2020/11/28 14:47:53 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define NB_TOKEN 10
# define NB_OPERATOR 8
# define ERROR -1
# define SUCCESS 0
# define ERROR_BASH 127
# define NEW_LINE '\n'
# define CTRL_D '\0'
# define IS_EVEN 0
# define ERRR0R_UNSET_VAR 1
# define IS_NOT_VARIABLE 1
# define FREE_ALL -1
# define ERROR_EXPORT 1
# define ERROR_CD 1
# define ERROR_REDIRECTION 1
# define ERROR_VARIABLE 1
# define SYNTAXE_ERROR 2
# define PERMISSION_DENIED 126

typedef enum		e_token_type
{
	and,
	or,
	semicolon,
	simple_redir_left,
	simple_redir_right,
	double_redir_left,
	double_redir_right,
	pipeline,
	option_command,
	single_quote,
	double_quote,
	backslash,
	literal,
	variable,
	space,
}					t_token_type;

typedef struct		s_token
{
	void			*value;
	t_token_type	type;
}					t_token;

typedef struct		s_builtin
{
	char			*value;
	void			(*ptr_fct)();
}					t_builtin;

typedef struct		s_operator
{
	t_token_type	type;
	void			(*ptr_fct)();
}					t_operator;

typedef struct		s_info
{
	t_list			*list_env;
	void			*ptr;
	t_list			*list_input;
	t_list			*list_path;
	char			**tab_var_env;
	int				ret;
}					t_info;

t_info				g_info;

#endif
