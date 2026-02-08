
#include "ccc_define.h"
#include "arena.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

FILE	*create_random_fp(char *asm_file_name);

FILE	*open_asm_file(char *asm_file_name)
{
	FILE	*asm_file = create_random_fp(asm_file_name);
	if (!asm_file)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	return (asm_file);
}

FILE	*create_random_fp(char *asm_file_name)
{
	int			fd;
	FILE		*fp;

	fd = mkstemps(asm_file_name, 2);
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
