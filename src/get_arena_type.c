
#include "../includes/malloc.h"

int		get_arena_type(size_t size)
{
	if (size <= MAX_TINY)
		return (TINY);
	else if (size <= MAX_SMALL)
		return (SMALL);
	else
		return (LARGE);
}
