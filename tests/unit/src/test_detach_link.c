#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"

t_header	*get_testing_list(void)
{
	t_header	*list;
	t_header	*tmp;

	list = (t_header*)mmap(0, 1024, MMAP_PROT, MMAP_FLAGS, -1, 0);
	tmp = list;
	list->prev = NULL;
	list->size = 1;
	list->next = list + sizeof(t_header);
	list->next->prev = list;
	list = list->next;
	list->size = 2;
	list->next = list + sizeof(t_header);
	list->next->prev = list;
	list = list->next;
	list->size = 3;
	list->next = NULL;
	return (tmp);
}

void	test_detach_first_link(void)
{
	t_header	*list;
	t_header	*link;
	t_header	*tmp;

	list = get_testing_list();
	tmp = list;
	link = list;
	detach_link(&list, link);
	TEST_ASSERT_EQUAL(link->next, NULL);
	TEST_ASSERT_EQUAL(link->prev, NULL);
	TEST_ASSERT_EQUAL(link->size, 1);
	TEST_ASSERT_EQUAL(list->prev, NULL);
	TEST_ASSERT_EQUAL(list->size, 2);
	list = list->next;
	TEST_ASSERT_EQUAL(list->size, 3);
	TEST_ASSERT_EQUAL(list->next, NULL);
	munmap(tmp, 1024);
}

void	test_detach_middle_link(void)
{
	t_header	*list;
	t_header	*link;
	t_header	*tmp;

	list = get_testing_list();
	tmp = list;
	link = list->next;
	detach_link(&list, link);
	TEST_ASSERT_EQUAL(link->next, NULL);
	TEST_ASSERT_EQUAL(link->prev, NULL);
	TEST_ASSERT_EQUAL(link->size, 2);
	TEST_ASSERT_EQUAL(list->prev, NULL);
	TEST_ASSERT_EQUAL(list->size, 1);
	list = list->next;
	TEST_ASSERT_EQUAL(list->size, 3);
	TEST_ASSERT_EQUAL(list->next, NULL);
	munmap(tmp, 1024);
}

void	test_detach_last_link(void)
{
	t_header	*list;
	t_header	*link;
	t_header	*tmp;

	list = get_testing_list();
	tmp = list;
	link = list->next->next;
	detach_link(&list, link);
	TEST_ASSERT_EQUAL(link->next, NULL);
	TEST_ASSERT_EQUAL(link->prev, NULL);
	TEST_ASSERT_EQUAL(link->size, 3);
	TEST_ASSERT_EQUAL(list->prev, NULL);
	TEST_ASSERT_EQUAL(list->size, 1);
	list = list->next;
	TEST_ASSERT_EQUAL(list->size, 2);
	TEST_ASSERT_EQUAL(list->next, NULL);
	munmap(tmp, 1024);
}

void	test_detach_link(void)
{
	test_detach_first_link();
	printf("first link [OK]\n");
	test_detach_middle_link();
	printf("middle link [OK]\n");
	test_detach_last_link();
	printf("last link [OK]\n");
}
