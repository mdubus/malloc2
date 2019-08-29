#include "../includes/malloc.h"

t_header	*get_link(void *ptr)
{
	t_header	*tmp;
	t_header	*link;

	tmp = l.used;
	link = NULL;
	while (tmp != NULL)
	{
		if ((char *)tmp + sizeof(t_header) == (char *)ptr)
			return tmp;
		tmp = tmp->next;
	}
	return (link);
}

void	ft_free(void *ptr)
{
	int			arena_type;
	t_header	*link;
	t_header	*list;

	arena_type = -1;
	if (ptr == NULL)
		return ;
	if ((link = get_link(ptr)) == NULL)
		return ;
	else
	{
		detach_link(&l.used, &link);
		arena_type = get_arena_type(link->size);
		list = l.free[arena_type];
		insert_link_in_list(&list, &link);
	}
}
