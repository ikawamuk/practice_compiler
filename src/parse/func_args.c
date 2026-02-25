

#include"tree.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool	is_expected(const char *op, t_token *token);
t_tree	*variable(t_token **token_p);

/*
func_args   = "(" (ident ",")* ")"
*/
t_tree  *func_args(t_token **token_p)
{
    if (is_expected("(", *token_p))
	{
		*token_p = (*token_p)->next;
	    while ((*token_p)->type != TK_EOF && !is_expected(")", *token_p))
	    {
            variable(token_p);
        	*token_p = (*token_p)->next;
            if (is_expected(",", *token_p))
                *token_p = (*token_p)->next;
	    }
        fprintf(stderr, "expected \')\'\n");
    }
    else
        fprintf(stderr, "expected \'(\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
