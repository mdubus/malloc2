
#include "../Unity/src/unity.h"
#include "../../../includes/malloc.h"

void	test_cant_split_1(void)
{
	size_t	size;

	size = 10 + sizeof(t_header);
	l.free[TINY] = (t_header*)mmap(0, size, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&l.free[TINY]);
	l.free[TINY]->size = 10;
	split_block(&l.free[TINY], 10);
	TEST_ASSERT_EQUAL(l.free[TINY]->next, NULL);
	munmap(l.free[TINY], size);
}

void	test_cant_split_2(void)
{
	size_t	size;

	size = 10 + (2 * sizeof(t_header));
	l.free[TINY] = (t_header*)mmap(0, size, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&l.free[TINY]);
	l.free[TINY]->size = 10 + sizeof(t_header);
	split_block(&l.free[TINY], 10);
	TEST_ASSERT_EQUAL(l.free[TINY]->next, NULL);
	munmap(l.free[TINY], size);
}

void	test_split(void)
{
	size_t	size;

	size = 20 + (2 * sizeof(t_header));
	l.free[TINY] = (t_header*)mmap(0, size, MMAP_PROT, MMAP_FLAGS, -1, 0);
	create_new_link(&l.free[TINY]);
	l.free[TINY]->size = 20 + sizeof(t_header);
	split_block(&l.free[TINY], 10);
	TEST_ASSERT_EQUAL(l.free[TINY]->size, 10);
	TEST_ASSERT_EQUAL(l.free[TINY]->next->size, 10);
	munmap(l.free[TINY], size);
}

void	test_split_block(void)
{
	test_cant_split_1();
	printf("can't split 1 [OK]\n");
	test_cant_split_2();
	printf("can't split 2 [OK]\n");
	test_split();
	printf("test split [OK]\n");
}
