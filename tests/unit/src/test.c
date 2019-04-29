#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"



int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_create_new_link);
	RUN_TEST(test_get_padded_size);
	RUN_TEST(test_create_new_memory_block);
	return UNITY_END();
}
