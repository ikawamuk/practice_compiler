/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:58:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 19:23:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	generate_mod(FILE *assem_src)
{
	fprintf(assem_src, "\tcqo\n");
	fprintf(assem_src, "\tidiv rdi\n");
	fprintf(assem_src, "\tmov rax, rdx\n");
}
