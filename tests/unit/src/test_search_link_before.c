
#include "../../../includes/malloc.h"
#include "../Unity/src/unity.h"

void		test_before_null()
{
	t_header	*list;
	t_header	*tmp;

	list = (t_header*)mmap(0, 10, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&list);
	tmp = search_link_before(list, list);
	TEST_ASSERT_EQUAL(tmp, list);
	munmap(list, 10);
}

void	test_middle_link()
{
	t_header	*list;
	t_header	*tmp;
	t_header	*link_before;

	list = (t_header*)mmap(0, 100, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&list);
	tmp = list;
	list->next = list + sizeof(t_header) +  10;
	list->size = 10;
	list = list->next;
	list->next = list + sizeof(t_header) +  15;
	list->size = 15;
	list->next = NULL;
	list = tmp->next;
	link_before = search_link_before(list, tmp);
	TEST_ASSERT_EQUAL(link_before, tmp);
	munmap(tmp, 100);
}



void	test_search_link_before(void)
{
	test_before_null();
	test_middle_link();
}
