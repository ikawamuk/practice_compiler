/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:10:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/01 20:55:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>
#include <aio.h>

static ssize_t	get_file_size(FILE *fp);

char	*file_path_to_str(const char *file_path)
{
	FILE	*fp = fopen(file_path, "rb");
	if (!fp)
		return (NULL);
	ssize_t	size = get_file_size(fp);
	if (size < 0)
		return (NULL);
	char	*buffer = aalloc(size + 2);
	if (!buffer)
		return (fclose(fp), NULL);
	if (fread(buffer, sizeof(char), (size_t)size, fp) != (size_t)size)
		return (fclose(fp), NULL);
	fclose(fp);
	if (size == 0 || buffer[size - 1] != '\n')
		buffer[size++] = '\n';
	buffer[size] = '\0';
	return (buffer);
}

static ssize_t	get_file_size(FILE *fp)
{
	rewind(fp);
	fseek(fp, 0, SEEK_END);
	ssize_t	size = (ssize_t)ftell(fp);
	if (size == -1)
		return (-1);
	rewind(fp);
	return (size);
}
