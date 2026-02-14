/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:49:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 23:02:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

void	generate_return(FILE *assem_src)
{
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tmov rsp, rbp\n");
	fprintf(assem_src, "\tpop rbp\n");
	fprintf(assem_src, "\tret\n");
}