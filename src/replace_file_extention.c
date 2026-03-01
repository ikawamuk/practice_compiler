
#include <string.h>
#include <stdlib.h>

char	*replace_file_extention(const char *file_name, const char *new_extention)
{
	char    *last_dot = strrchr(file_name, '.');
	size_t  base_len; 
	if (!last_dot)
		base_len = strlen(file_name);
	else
		base_len = last_dot - file_name;
	char    *new_file_name  = malloc(base_len + strlen(new_extention) + 1);
	if (!new_file_name)
		return (NULL);
	memcpy(new_file_name, file_name, base_len);
	strcpy(new_file_name + base_len, new_extention);
	return (new_file_name);
}
