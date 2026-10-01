
#include "ccc_define.h"
#include "arena.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	open_assem_fd(char *assem_src_fd_name)
{
	int	asm_fd = mkstemps(assem_src_fd_name, 2);
	if (asm_fd == -1)
	{
		clear_arena();
		exit(EXIT_FAILURE);
	}
	return (asm_fd);
}

