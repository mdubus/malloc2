#include "../../../includes/malloc.h"
#include "../Unity/src/unity.h"

t_header	*get_testing_list(void)
{
	t_header	*list;
	t_header	*tmp;

	list = (t_header*)mmap(0, 1024, MMAP_PROT, MMAP_FLAGS, -1, 0);
	tmp = list;
	list->prev = NULL;
	list->next = list + sizeof(t_header);
	list->next->prev = list;
	list = list->next;
	list->next = list + sizeof(t_header);
	list->next->prev = list;
	list = list->next;
	list->next = NULL;
	return tmp;
}
