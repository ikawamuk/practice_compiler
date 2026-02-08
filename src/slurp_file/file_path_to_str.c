/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:10:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 17:18:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>

static size_t	get_file_size(FILE *fp);

char	*file_path_to_str(const char *file_path)
{
	FILE	*fp = fopen(file_path, "rb");
	if (!fp)
		return (NULL);
	size_t	size = get_file_size(fp);
	if (size == 0)
		return (NULL);
	char	*buffer = aalloc(size + 1);
	if (!buffer)
		return (fclose(fp), NULL);
	if (fread(buffer, sizeof(char), size, fp) != size)
		return (fclose(fp), NULL);
	fclose(fp);
	buffer[size] = '\0';
	return (buffer);
}

static size_t	get_file_size(FILE *fp)
{
	rewind(fp);
	fseek(fp, 0, SEEK_END);
	long	size = ftell(fp);
	if (size == -1)
		return (0);
	rewind(fp);
	return ((size_t)size);
}
