#include "main.h"

/**
 * free_str - frees an array of strings
 * @d_ptr: pointer to array of strings
 */

void free_str(char **d_ptr)
{
	int itr = 0;

	if (d_ptr == NULL)
		return;
	while (d_ptr[itr] != NULL)
	{
		free(d_ptr[itr++]);
	}
	free(d_ptr);
}
