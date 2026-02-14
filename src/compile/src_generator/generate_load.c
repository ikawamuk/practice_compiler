/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_left_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 23:02:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_load(FILE *assem_src)
{
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tmov rax, [rax]\n");
	fprintf(assem_src, "\tpush rax\n");
}