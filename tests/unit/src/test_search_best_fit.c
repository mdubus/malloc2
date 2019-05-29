#include "../../../includes/malloc.h"
#include "../Unity/src/unity.h"

t_header	*test_ascending_size(t_header *list)
{
	t_header	*tmp;

	tmp = list;
	list->size = 1;
	list->next = list + sizeof(t_header);
	list = list->next;
	list->size = 2;
	list->next = list + sizeof(t_header);
	list = list->next;
	list->size = 3;
	return (search_best_fit(tmp));
}

t_header	*test_descending_size(t_header *list)
{
	t_header	*tmp;

	tmp = list;
	list->size = 3;
	list->next = list + sizeof(t_header);
	list = list->next;
	list->size = 2;
	list->next = list + sizeof(t_header);
	list = list->next;
	list->size = 1;
	return (search_best_fit(tmp));
}

t_header	*test_unordered_sizes(t_header *list)
{
	t_header	*tmp;

	tmp = list;
	list->size = 2;
	list->next = list + sizeof(t_header);
	list = list->next;
	list->size = 3;
	list->next = list + sizeof(t_header);
	list = list->next;
	list->size = 1;
	return (search_best_fit(tmp));
}

t_header	*test_zero_size(t_header *list)
{
	t_header	*tmp;

	tmp = list;
	list->size = 0;
	return (search_best_fit(tmp));
}

t_header	*test_no_result()
{
	t_header	*tmp;

	tmp = NULL;
	return search_best_fit(tmp);
}

void  test_search_best_fit(void)
{
	t_header	*list;

	list = (t_header*)mmap(0, 1024, MMAP_PROT, MMAP_FLAGS, -1, 0);
	TEST_ASSERT_EQUAL((test_ascending_size(list))->size, 1);
	printf("ascending size [OK]\n");
	TEST_ASSERT_EQUAL((test_descending_size(list))->size, 1);
	printf("descending size [OK]\n");
	TEST_ASSERT_EQUAL((test_unordered_sizes(list))->size, 1);
	printf("unordered sizes [OK]\n");
	TEST_ASSERT_EQUAL((test_zero_size(list))->size, 0);
	printf("zero size [OK]\n");
	TEST_ASSERT_EQUAL(test_no_result(), NULL);
	printf("no best fit [OK]\n");
	munmap(list, 1024);
}

