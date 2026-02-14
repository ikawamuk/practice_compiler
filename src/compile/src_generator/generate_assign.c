/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:56:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 00:33:32 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_assign(FILE *assem_src)
{
	fprintf(assem_src, "\tpop rdi\n");
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tmov [rax], rdi\n");
	fprintf(assem_src, "\tpush rdi\n");
}