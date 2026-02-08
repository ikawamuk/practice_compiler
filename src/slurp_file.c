/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slurp_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:55:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 16:47:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	get_file_size(FILE *fp);

char	*slurp_file(const char *file_path)
{
	char	*file_content = read_file_content(file_path);
	if (!file_content)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	return (file_content);
}

char	*read_file_content(const char *file_path)
{
	FILE	*fp = fopen(file_path, "r");
	if (!fp)
		return (EXIT_FAILURE);
	char	*file_content = read_in_bulk(fp);
	fclose(fp);
	return (file_content);
}

static char	*read_in_bulk(FILE *fp)
{
	size_t	size = get_file_size(fp);
	char	*buffer = aalloc(size + 1);
	if (buffer == NULL)
		return (NULL);
	if (fread(buffer, sizeof(char), size, fp) != size)
		return (NULL);
	buffer[size] = '\0';
	return (buffer);
}

static size_t	get_file_size(FILE *fp)
{
	rewind(fp);
	fseek(fp, 0, SEEK_END);
	long	size = ftell(fp);
	rewind(fp);
	return ((size_t)size);
}
