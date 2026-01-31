#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*read_in_bulk(const char *file_path);
int		compile(char *input);

int	main(int argc, char *argv[])
{
	char	*input;

	input = read_in_bulk(argv[1]);
	if (compile(input) != 0)
	{
		free(input);
		return (EXIT_FAILURE);
	}
	free(input);
	return (EXIT_SUCCESS);
}
