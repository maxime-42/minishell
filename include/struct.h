#ifndef STRUCT_H
# define STRUCT_H
#define NB_TOKEN	10
#define NB_OPERATOR 8
# define NEW_LINE '\n'
# define CTRL_D '\0'
# define IS_EVEN 0
# define ERRR0R_UNSET_VAR 1
# define IS_NOT_VARIABLE 1
# define FREE_ALL -1
# define ERROR_EXPORT 1
# define SYNTAXE_ERROR 2
# define PERMISSION_DENIED 126
typedef enum		s_token_type
{
	and,//0
	or,//1
	semicolon,//2
	simple_redir_left,//3
	simple_redir_right,//4
	double_redir_left,//5
	double_redir_right,//6
	pipeline,//7
	option_command,//8
	single_quote,//9
	double_quote,//10
	backslash,//11
	literal,//12
	variable,//13
	space,//14
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
	t_list			*list_env;
	void			*ptr;
	t_list			*list_input;
	t_list			*list_path;
	unsigned char	status : 3; 
	char			**tab_var_env;
	int				ret;
}					t_info;

t_info			  g_info;
#endif