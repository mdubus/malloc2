#include "../../../includes/malloc.h"
#include "../Unity/src/unity.h"

void	test_get_padded_size(void)
{
	TEST_ASSERT_EQUAL(get_padded_size(0), 0);
	TEST_ASSERT_EQUAL(get_padded_size(1), 8);
	TEST_ASSERT_EQUAL(get_padded_size(7), 8);
	TEST_ASSERT_EQUAL(get_padded_size(8), 8);
	TEST_ASSERT_EQUAL(get_padded_size(9), 16);
}
