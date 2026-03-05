

#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	error_at(const char *location, const char *err_msg);
t_tree	*num(t_token **token_p);
t_tree	*ident(t_token **token_p);
bool	is_expected(const char *op, t_token *token);

/*
value	= num 
		| ident
*/
t_tree	*value(t_token **token_p)
{
	if ((*token_p)->type == TK_NUM)
		return (num(token_p));
	if ((*token_p)->type == TK_IDENT)
		return (ident(token_p));
	error_at((*token_p)->str, "unexpected token\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
