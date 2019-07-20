
#include "../includes/malloc.h"

t_header	*search_link_before(t_header *link, t_header *list)
{
	t_header	*tmp;

	tmp = list;
	while (tmp->next != NULL && tmp->next < link)
		tmp = tmp->next;
	return tmp;
}
