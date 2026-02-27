

#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	fprintf(stderr, "unexpected token %.*s\n", (*token_p)->len, (*token_p)->str);
	clear_arena();
	exit(EXIT_FAILURE);
}
