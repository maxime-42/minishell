#ifndef STRUCT_H
# define STRUCT_H

#define NB_TOKEN    10
#define NB_OPERATOR 8

typedef enum        s_token_type
{
    and,
    or,
    pipe,
    redir_left,
    redir_right,
    double_redir_left,
    double_redir_right,
    semicolon,
    shortcut_option,
    option_command,
    long_option,
    simple_quote,
    double_quote,
    var,
    command,
    arg_command,
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
    char            **array_env;
    int             ret;
}                   t_info;

t_info              g_info;
#endif