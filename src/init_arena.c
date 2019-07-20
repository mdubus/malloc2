
#include "../includes/malloc.h"

size_t	get_max_arena_size(int arena_type)
{
	size_t	page_size;

	page_size = getpagesize();
	if (arena_type == TINY)
		return (MAX_TINY * page_size);
	if (arena_type == SMALL)
		return (MAX_SMALL * page_size);
	return (0);
}

int		init_arena(int arena_type)
{
	size_t	max_arena_size;

	max_arena_size = get_max_arena_size(arena_type);
	l.free[arena_type] = create_new_memory_block(max_arena_size + sizeof(t_header));
	if (l.free[arena_type] == NULL)
		return (1);
	create_new_link(&l.free[arena_type]);
	l.free[arena_type]->size = max_arena_size;
	return (0);
}
