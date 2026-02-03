/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_bulk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:39:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/02 20:16:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static FILE		*xfopen(const char *file_name, const char *modes);
static size_t	get_file_size(FILE *fp);
static char		*read_file_content(FILE *input_file);

char	*read_in_bulk(const char *file_path)
{
	FILE	*input_file;
	char	*buffer;

	input_file = xfopen(file_path, "r");
	buffer = read_file_content(input_file);
	if (!buffer)
	{
		fclose(input_file);
		return (NULL);
	}
	fclose(input_file);
	return (buffer);
}

static char	*read_file_content(FILE *input_file)
{
	char	*buffer;
	size_t	size;

	size = get_file_size(input_file);
	buffer = calloc(size + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (fread(buffer, sizeof(char), size, input_file) != size)
	{
		free(buffer);
		return (NULL);
	}
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

static FILE	*xfopen(const char *file_name, const char *modes)
{
	FILE	*fp;

	fp = fopen(file_name, modes);
	if (!fp)
		exit(EXIT_FAILURE);
	return (fp);
}
