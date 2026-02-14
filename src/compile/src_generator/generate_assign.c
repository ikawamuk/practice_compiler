/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:56:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 23:05:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_assign(FILE *assem_src)
{
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tmov rsp, rbp\n");
	fprintf(assem_src, "\tpop rbp\n");
	fprintf(assem_src, "\tret\n");
}