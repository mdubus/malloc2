#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"

void	test_create_new_memory_block(void) {
	void	*ptr;

	ptr = create_new_memory_block(MAX_TINY * getpagesize());
	TEST_ASSERT(ptr != NULL);
	munmap(ptr, MAX_TINY * getpagesize());
	ptr = create_new_memory_block(0);
	TEST_ASSERT(ptr == NULL);
	ptr = create_new_memory_block(-1);
	TEST_ASSERT(ptr == NULL);
}
