#include "../../../includes/malloc.h"
#include "../Unity/src/unity.h"

void insert_in_middle(void)
{
	t_header	*list;
	t_header	*tmp;
	t_header	*link;

	list = (t_header*)mmap(0, 100, MMAP_PROT, MMAP_FLAGS, -1, 0);
	link = (t_header*)mmap(0, 100, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&list);
	create_new_link(&link);
	tmp = list;
	list->size = 10;
	list->next = list + sizeof(t_header) +  10;
	list->next->prev = list;
	list = list->next;
	list->size = 15;
	list->next = NULL;
	list = tmp;
	link->size = 80;
	insert_link_after(&list, &link);
	TEST_ASSERT_EQUAL(list->next->size, 80);
	TEST_ASSERT_EQUAL(list->next->prev, list);
	munmap(list, 100);
	munmap(link, 100);
}

void	insert_next_null(void)
{
	t_header	*list;
	t_header	*link;

	list = (t_header*)mmap(0, 100, MMAP_PROT, MMAP_FLAGS, -1, 0);
	link = (t_header*)mmap(0, 100, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&list);
	create_new_link(&link);
	list->size = 10;
	link->size = 80;
	insert_link_after(&list, &link);
	TEST_ASSERT_EQUAL(list->next->size, 80);
	TEST_ASSERT_EQUAL(list->next->prev, list);
	TEST_ASSERT_EQUAL(list->next->next, NULL);
	munmap(list, 100);
	munmap(link, 100);
}

void	test_insert_link_after(void)
{
	insert_in_middle();
	printf("insert in middle [OK]\n");
	insert_next_null();
	printf("insert next null [OK]\n");
}

