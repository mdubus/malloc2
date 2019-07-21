#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"



int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_create_new_link);
	RUN_TEST(test_get_padded_size);
	RUN_TEST(test_create_new_memory_block);
	RUN_TEST(test_search_best_fit);
	RUN_TEST(test_detach_link);
	RUN_TEST(test_split_block);
	RUN_TEST(test_search_link_before);
	RUN_TEST(test_insert_link_after);
	return UNITY_END();
}
