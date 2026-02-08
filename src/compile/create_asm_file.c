
#include "ccc_define.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

FILE    *create_asm_file(char *asm_file_name)
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
