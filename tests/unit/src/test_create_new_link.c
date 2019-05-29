#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"

void	test_create_new_link(void) {
	create_new_link(&l.free.tiny);
	create_new_link(&l.free.header);
	TEST_ASSERT_EQUAL(l.free.tiny.size, 0);
	TEST_ASSERT_EQUAL(l.free.tiny.data, NULL);
	TEST_ASSERT_EQUAL(l.free.tiny.prev, NULL);
	TEST_ASSERT_EQUAL(l.free.tiny.next, NULL);
}
