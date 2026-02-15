

#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

t_tree	*num(t_token **token_p);
t_tree	*ident(t_token **token_p);
bool	is_expected(const char *op, t_token *token);
t_tree	*func_call(t_token **token_p);

/*
value	= num 
		| ident ("(" ")")?

*/
t_tree	*value(t_token **token_p)
{
	if ((*token_p)->type == TK_NUM)
		return (num(token_p));
	if ((*token_p)->type == TK_IDENT)
	{
		if (is_expected("(", (*token_p)->next))
			return (func_call(token_p));
		return (ident(token_p));
	}
	fprintf(stderr, "unexpected token\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
