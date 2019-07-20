
#include "../includes/malloc.h"

int		get_arena_type(size_t size)
{
	if (size <= MAX_TINY)
		return (TINY);
	if (size <= MAX_SMALL)
		return (SMALL);
	return (LARGE);
}
