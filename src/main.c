/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/04/21 16:02:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

int	run_compiler(char **file_names);

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "no input file\n");
		fprintf(stderr, "Usage: ccc < C file > < object file ... >\n");
		return (EXIT_FAILURE);
	}
	return (run_compiler(argv + 1));
}
