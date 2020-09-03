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
    shortcut_option,//8
    option_command,//9
    long_option,//10
    single_quote,//11
    double_quote,//12
    backslash,//13
    literale,//14
    var,//15
    command,//16
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
    void            *generic_ptr;
    int             ret;
}                   t_info;

t_info              g_info;
#endif