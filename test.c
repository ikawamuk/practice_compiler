#include <stdio.h>
#include <stddef.h>

int main()
{
	size_t	v = 0;
	size_t	*p = &v;
	// size_t	**p2 = &p;

	printf("p:%p\n", p);
	printf("p:%p\n", p + 1);
	printf("p:%p\n", 1 + p);
	// printf("p:%p\n", p + p2);
}