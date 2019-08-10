
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

t_header	*init_arena(size_t size)
{
	t_header	*arena;
	int			arena_type;
	size_t		arena_size;

	arena_type = get_arena_type(size);
	if (arena_type == LARGE)
		arena_size = size;
	else
		arena_size = get_max_arena_size(arena_type);
	arena = create_new_memory_block(arena_size + sizeof(t_header));
	create_new_link(&arena);
	arena->size = arena_size;
	return (arena);
}
