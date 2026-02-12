

#include<stdbool.h>

bool	is_identifier_char(char c)
{
	return (('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z')
		|| ('0' <= c && c <= '9')
		|| ('_' == c));
}
