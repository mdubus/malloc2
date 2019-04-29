#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"

void	test_create_new_memory_block(void) {
	l.free.tiny.data = create_new_memory_block(MAX_TINY * getpagesize());
	
	TEST_ASSERT_EQUAL(sizeof(l.free.tiny.data), MAX_TINY * getpagesize());
}


int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_create_new_link);
	RUN_TEST(test_get_padded_size);
//	RUN_TEST(test_create_new_memory_block);
	return UNITY_END();
}
