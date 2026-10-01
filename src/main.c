/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/02 02:24:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	compile(char **file_names);

int	main(int argc, char *argv[]) {
	if (argc < 2) {
		dprintf(2, "no input file\n");
		dprintf(2, "Usage: ccc < C file > < object file to link... >\n");
		return (1);
	}
	if (compile(argv + 1) < 0)
		return (1);
	return (0);
}
