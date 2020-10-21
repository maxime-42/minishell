#ifndef STRUCT_H
# define STRUCT_H

#define NB_TOKEN	10
#define NB_OPERATOR 8
#define STR_OPERATOR "><>|&;"
typedef enum		s_token_type
{
	and,//0
	or,//1
	pipeline,//2
	simple_redir_left,//3
	simple_redir_right,//4
	double_redir_left,//5
	double_redir_right,//6
	semicolon,//7
	option_command,//8
	single_quote,//9
	double_quote,//10
	backslash,//11
	literal,//12
	variable,//13
	status,//14
	space,//15
	eof,//16
}					t_token_type;

typedef struct		s_token
{
	void			*value;
	t_token_type	type;
}				   t_token;


typedef struct	  s_builtin
{
	char			*value;
	void			(*ptr_fct)();
}					t_builtin;

typedef struct		s_operator
{
	t_token_type	 type;
	void			(*ptr_fct)();
}					t_operator;

typedef struct		info
{
	t_btree			*root;
	t_list			*list_env;
	t_list			*list_input;
	char			*str_input;
	t_list			*list_path;
	char			**tab_var_env;
	t_list			*stack;
	int				ret;
	int				new_fd;
}					t_info;

t_info			  g_info;
#endif