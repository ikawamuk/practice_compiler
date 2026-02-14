/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:05:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 04:17:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "arena.h"
#include "token.h"
#include "function.h"
#include <stdlib.h>

t_function	*program(t_token **token_p);

t_function	*parse(t_token *token_list)
{
	t_function	*main_function = program(&token_list);
	if (!main_function)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	return (main_function);
}
