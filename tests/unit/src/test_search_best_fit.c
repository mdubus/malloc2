#include "../../../includes/malloc.h"
#include "../Unity/src/unity.h"

void	test_ascending_size(void)
{
	t_header	*list;
	t_header	*tmp;
	t_header	*best_fit;

	list = get_testing_list();
	tmp = list;
	list->size = 1;
	list->next->size = 2;
	list->next->next->size = 3;
	best_fit = search_best_fit(tmp, 1);
	TEST_ASSERT_EQUAL(best_fit->size, 1);
	munmap(tmp, 1024);
}

void	test_descending_size(void)
{
	t_header	*list;
	t_header	*tmp;
	t_header	*best_fit;

	list = get_testing_list();
	tmp = list;
	list->size = 3;
	list->next->size = 2;
	list->next->next->size = 1;
	best_fit = search_best_fit(tmp, 3);
	TEST_ASSERT_EQUAL(best_fit->size, 3);
	munmap(tmp, 1024);
}

void	test_unordered_sizes(void)
{
	t_header	*list;
	t_header	*tmp;
	t_header	*best_fit;


	list = get_testing_list();
	tmp = list;
	list->size = 2;
	list->next->size = 3;
	list->next->next->size = 1;
	best_fit = search_best_fit(tmp, 3);
	TEST_ASSERT_EQUAL(best_fit->size, 3);
	munmap(tmp, 1024);
}

void	test_no_result(void)
{
	t_header	*tmp;
	t_header	*best_fit;

	tmp = NULL;
	best_fit = search_best_fit(tmp, 1);
	TEST_ASSERT_EQUAL(best_fit, NULL);
}


void  test_search_best_fit(void)
{
	test_ascending_size();
	printf("ascending size [OK]\n");
	test_descending_size();
	printf("descending size [OK]\n");
	test_unordered_sizes();
	printf("unordered sizes [OK]\n");
	test_no_result();
	printf("no best fit [OK]\n");
}

