/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:50:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/03 18:06:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "arena.h"
# include "token.h"
# include "tree.h"
# include <stdio.h>

typedef struct s_ctx
{
	t_arena	arena;
	// 
	char	*file_path;
	FILE	*fp;
	char	*file_content;
	// 
	t_token	*token_list;
	t_tree	*ast;
}	t_ctx;

#endif
