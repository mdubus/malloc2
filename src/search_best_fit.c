#include "../includes/malloc.h"

t_header	*search_best_fit(t_header *list)
{
	t_header	*best_fit;

	best_fit = list;
	while (list != NULL) {
		if (list->size < best_fit->size)
			best_fit = list;
		list = list->next;
	}
	return best_fit;
}
