
#include "../includes/malloc.h"

void	split_block(t_header **link,  size_t size)
{
	t_header	*next;

	if ((*link)->size > (size + sizeof(t_header)))
	{
		next = (*link)->next;
		(*link)->next = (void *)*link + size + sizeof(t_header);
		create_new_link(&(*link)->next);
		(*link)->next->prev = *link;
		(*link)->next->next = next;
		(*link)->next->size = (*link)->size - size - sizeof(t_header);
		(*link)->size = size;
	}
}
