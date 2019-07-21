
#include "../includes/malloc.h"

void	insert_link_in_list(t_header **list, t_header **link)
{
	t_header	*before;

	if (*list == NULL)
		*list = *link;
	else 
	{
		before = search_link_before(*link, *list);
		insert_link_after(&before, link);
	}
}
