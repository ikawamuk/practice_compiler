/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slurp_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:55:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/08 17:11:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

char		*file_path_to_str(const char *file_path);

char	*read_src(const char *file_path)
{
	char *file_content = file_path_to_str(file_path);
	if (!file_content)
	{
		perror("read_src");
		return (NULL);
	}
	return (file_content);
}
