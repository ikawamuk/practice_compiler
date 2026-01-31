/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:05:14 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 02:49:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool	consume_number(t_token **token_p);
bool	consume_op(t_token **token_p, char op);
void	error_at(char *input_str, char *location, char *err_msg);

int	put_operations(FILE *asm_file, t_token *list)
{
	t_token	*cur;
	char	op;

	cur = list;
	if (cur->type != TK_NUM)
	{
		error_at(list->str, cur->str, "Ccc: error: expression must start with a number\n");
		return (EXIT_FAILURE);
	}
	fprintf(asm_file, "\tmov rax, %d\n", cur->val);
	cur = cur->next;
	while (cur->type != TK_EOF)
	{
		if (cur->type != TK_RESERVED)
			return (error_at(list->str, cur->str, "Ccc: error: expected an operator after a number\n"), EXIT_FAILURE);
		op = cur->str[0];
		cur = cur->next;
		if (cur->type != TK_NUM)
			return (error_at(list->str, cur->str, "Ccc: error: expected a number after an opearation\n"), EXIT_FAILURE);
		if (op == '+')
			fprintf(asm_file, "\tadd rax, %d\n", cur->val);
		else if (op == '-')
			fprintf(asm_file, "\tsub rax, %d\n", cur->val);
		cur = cur->next;
	}
	return (EXIT_SUCCESS);
}



