/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:40:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 05:27:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "tree.h"
#include "token.h"
#include "arena.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

t_tree			*stmt(t_token **token_p);
t_lvar			*get_list(void);
void			clear_list_stack(void);
t_tree			*block(t_token **token_p);
bool			is_expected(const char *op, t_token *token);

t_function	*program(t_token **token_p)
{
	t_function	*main_function = aalloc(sizeof(t_function));
	if (!main_function)
		return (NULL);
	if (is_expected("{", *token_p))
	{
		*token_p = (*token_p)->next;
		main_function->ast = block(token_p);
		main_function->var_list = get_list();
		clear_list_stack();
		if (is_expected("}", *token_p))
			return (main_function);
		fprintf(stderr, "expected \'}\'\n");
		clear_arena();
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "expected \'{\'\n");
	clear_arena();
	exit(EXIT_FAILURE);
}
