#include <unistd.h>

void	print_ok(char a, char b)
{
	write(1, "ok ", 3);
	write(1, &a, 1);
	write(1, " ", 1);
	write(1, &b, 1);
	write(1, "\n", 1);
}
