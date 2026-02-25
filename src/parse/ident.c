
#include "tree.h"
#include "token.h"

t_tree	*func_call(t_token **token_p);
t_tree	*variable(t_token **token_p);

/*
ident   = func_call
        | variable
*/
t_tree	*ident(t_token **token_p)
{
    if (is_expected("(", (*token_p)->next))
		return (func_call(token_p));
	return (variable(token_p));
}