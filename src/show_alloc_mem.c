#include "../includes/malloc.h"

void	show_alloc_mem()
{
	t_header	*tmp;
	void		*begin;
	void		*end;

	tmp = l.used;
	while (tmp != NULL)
	{
		begin = (void *)tmp;
		end = (void *)tmp + sizeof(t_header);
		print_address((uintptr_t)begin);
		ft_putstr(" -- Header -- ");
		print_address((uintptr_t)end);
		ft_putstr(" -- ");
		ft_putnbr(tmp->size);
		ft_putstr(" -- ");
		print_address((uintptr_t)end + tmp->size);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}
