#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"

void	test_create_new_link(void) {
	create_new_link(&l.free[TINY]);
	TEST_ASSERT_EQUAL(l.free[TINY].size, 0);
	TEST_ASSERT_EQUAL(l.free[TINY].data, NULL);
	TEST_ASSERT_EQUAL(l.free[TINY].prev, NULL);
	TEST_ASSERT_EQUAL(l.free[TINY].next, NULL);
}
