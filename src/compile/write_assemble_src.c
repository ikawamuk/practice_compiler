/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_assemble_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/28 03:50:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void		generate_function(FILE *assem_src, t_function *func);
static void	write_hedder(FILE *assem_src);

void	write_assemble_src(FILE *assem_src, t_function *prog)
{
	write_hedder(assem_src);
	generate_function(assem_src, prog);
	return ;
}

static void	write_hedder(FILE *assem_src)
{
	fprintf(assem_src, ".intel_syntax noprefix\n");
	return ;
}

