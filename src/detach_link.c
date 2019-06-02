#include "../includes/malloc.h"

void	detach_link(t_header **list, t_header *link)
{
	if (link->prev == NULL) {
		*list = link->next;
		(*list)->prev = NULL;
	}
	else if (link->next == NULL)
		link->prev->next = NULL;
	else {
		link->prev->next = link->next;
		link->next->prev = link->prev;
	}
	link->prev = NULL;
	link->next = NULL;
}
