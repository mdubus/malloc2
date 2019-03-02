#include "../includes/malloc.h"

void	create_new_link(t_header *link)
{
	link->size = -1;
	link->data = NULL;
	link->prev = NULL;
	link->next = NULL;
}
