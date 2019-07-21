#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"

void	test_create_new_link(void)
{
	t_header	*list;

	list = (t_header*)mmap(0, 1024, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&list);
	TEST_ASSERT_EQUAL(list->size, 0);
	TEST_ASSERT_EQUAL(list->prev, NULL);
	TEST_ASSERT_EQUAL(list->next, NULL);
	munmap(list, 1024);
}
