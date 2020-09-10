#ifndef STRUCT_H
# define STRUCT_H

#define NB_TOKEN    10
#define NB_OPERATOR 8

typedef enum        s_token_type
{
    and,//0
    or,//1
    pipee,//2
    redir_left,//3
    redir_right,//4
    double_redir_left,//5
    double_redir_right,//6
    semicolon,//7
    option_command,//8
    single_quote,//9
    double_quote,//10
    backslash,//11
    literal,//12
    variable,//13
    command,//14
    space,//15
}                   t_token_type;

typedef struct      s_token
{
    void            *value;
    t_token_type    type;
}                   t_token;

typedef struct      info
{
    t_btree         *root;
    t_list          *list_env;
    t_list          *list_input;
    char            *str_input;
    void            *generic_ptr;
    int             ret;
}                   t_info;

t_info              g_info;
#endif