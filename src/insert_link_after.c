
#include "../includes/malloc.h"

void	insert_link_after(t_header **before, t_header **link)
{
	t_header	*tmp;

	tmp = (*before)->next;
	(*before)->next = *link;
	(*link)->prev = *before;
	(*link)->next = tmp;
	if (tmp != NULL)
		tmp->prev = *link;
}
