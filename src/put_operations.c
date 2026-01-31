/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:05:14 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 01:17:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool	consume_number(t_token **token_p);
bool	consume_op(t_token **token_p, char op);

int	put_operations(FILE *asm_file, t_token *list)
{
	char	op;

	if (list->type != TK_NUM)
	{
		fprintf(stderr, "Ccc: error: expression must start with a number\n");
		return (EXIT_FAILURE);
	}
	fprintf(asm_file, "\tmov rax, %d\n", list->data.val);
	while (list->type != TK_EOF)
	{
		if (list->type == TK_RESERVED)
		{
			op = list->data.str[0];
			list = list->next;
			if (op == '+')
				fprintf(asm_file, "\tadd rax, %d\n", list->data.val);
			else if (op == '-')
				fprintf(asm_file, "\tsub rax, %d\n", list->data.val);
		}
		list = list->next;
	}
	return (0);
}



