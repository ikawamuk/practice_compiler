/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_less_than.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:00:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 22:01:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	generate_less_than(FILE *asm_file)
{
	fprintf(asm_file, "\tcmp rax, rdi\n");
	fprintf(asm_file, "\tsetl al\n");
	fprintf(asm_file, "\tmovzb rax, al\n");
}
