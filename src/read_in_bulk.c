/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_bulk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/31 21:39:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static FILE	*xfopen(const char *file_path, const char *mode);
static size_t	get_file_size(FILE *fp);

char	*read_in_bulk(const char *file_path)
{
	FILE	*input_file;
	size_t	size;
	char	*buffer;

	input_file = xfopen(file_path, "r");
	size = get_file_size(input_file);
	buffer = malloc(size + 1);
	if (buffer == NULL)
	{
		fclose(input_file);
		exit(EXIT_FAILURE);
	}
	if (fread(buffer, sizeof(char), size, input_file) != size)
	{
		free(buffer);
		fclose(input_file);
		exit(EXIT_FAILURE);
	}
	fclose(input_file);
	return (buffer);
}

static size_t	get_file_size(FILE *fp)
{
	long size;

	rewind(fp);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	return ((size_t)size);
}

static FILE	*xfopen(const char *file_path, const char *mode)
{
	FILE	*fp = fopen(file_path, mode);

	if (!fp)
	{
		fprintf(stderr, "Failed to open the file\n");
		exit(EXIT_FAILURE);
	}
	return (fp);
}
