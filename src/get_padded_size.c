#include "../includes/malloc.h"

size_t	get_padded_size(size_t size)
{
	size_t	padded_size;

	padded_size = size;
	if (padded_size % sizeof(long) != 0)
		padded_size += (sizeof(long) - padded_size % sizeof(long));
	return (padded_size);
}
