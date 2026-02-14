/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_negative.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:59:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/14 23:02:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"
#include <stdio.h>

void	generate_negative(FILE *assem_src)
{
	fprintf(assem_src, "\tpop rax\n");
	fprintf(assem_src, "\tneg rax\n");
	fprintf(assem_src, "\tpush rax\n");
}