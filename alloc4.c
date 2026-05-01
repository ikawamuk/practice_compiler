#include <stdlib.h>
int alloc4(int **p, int first, int second, int third, int fourth)
{
	*p = malloc(4 * 4);
	if (!*p)
		return (-1);
	(*p)[0] = first;
	(*p)[1] = second;
	(*p)[2] = third;
	(*p)[3] = fourth;
	return (0);
}