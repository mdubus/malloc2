#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"

void	test_create_new_link(void) {

	l.free[TINY] = (t_header*)mmap(0, 1024, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&l.free[TINY]);
	TEST_ASSERT_EQUAL(l.free[TINY]->size, 0);
	TEST_ASSERT_EQUAL(l.free[TINY]->prev, NULL);
	TEST_ASSERT_EQUAL(l.free[TINY]->next, NULL);
	munmap(l.free[TINY], 1024);
}
