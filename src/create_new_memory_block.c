#include "../includes/malloc.h"

void	*create_new_memory_block(size_t size) {
	void	*ptr;

	ptr = mmap(0, size, MMAP_PROT, MMAP_FLAGS, -1, 0);
	if (ptr == MAP_FAILED)
		return NULL;
	return ptr;
}
