
#include "ccc_define.h"
#include "arena.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

FILE	*create_random_fp(char *assem_src_name);

FILE	*open_assem_src(char *assem_src_name)
{
	FILE	*assem_src = create_random_fp(assem_src_name);
	if (!assem_src)
	{
		clear_arena();
		free(assem_src);
		exit(EXIT_FAILURE);
	}
	return (assem_src);
}

FILE	*create_random_fp(char *assem_src_name)
{
	int			fd;
	FILE		*fp;

	fd = mkstemps(assem_src_name, 2);
	if (fd == -1)
	{
		fprintf(stderr, "Ccc: error: failed to open the file\n");
		return (NULL);
	}
	fp = fdopen(fd, "w");
	if (!fp)
	{
		close(fd);
		fprintf(stderr, "Ccc: error: failed to open the file\n");
		return (NULL);
	}
	return (fp);
}
