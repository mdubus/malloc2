#include "../includes/malloc.h"

char	*get_arena_name(int arena_type)
{
	if (arena_type == 0)
		return ("TINY");
	else if (arena_type == 1)
		return ("SMALL");
	else
		return ("LARGE");
}

void	print_arena_type(t_header *tmp, int arena_type, int *prev_arena_type)
{
	ft_putstr(get_arena_name(arena_type));
	ft_putstr(" : ");
	print_address((uintptr_t)tmp);
	ft_putstr("\n");
	*prev_arena_type = arena_type;
}

void	print_link_adresses(t_header *tmp)
{
	uintptr_t	header_end;
	uintptr_t	data_end;

	header_end = (uintptr_t)tmp + sizeof(t_header);
	data_end = (uintptr_t)header_end + tmp->size;
	print_address(header_end);
	ft_putstr(" - ");
	print_address(data_end);
	ft_putstr(" : ");
	ft_putnbr(tmp->size);
	ft_putstr(" octets\n");
}

void	show_alloc_mem()
{
	t_header			*tmp;
	int					arena_type;
	int					prev_arena_type;
	unsigned long long	total_size;

	tmp = l.used;
	total_size = 0;
	if (tmp != NULL)
	{
		prev_arena_type = -1;
		while (tmp != NULL)
		{
			arena_type = get_arena_type(tmp->size);
			if (arena_type != prev_arena_type)
				print_arena_type(tmp, arena_type, &prev_arena_type);
			print_link_adresses(tmp);
			total_size += tmp->size;
			tmp = tmp->next;
		}
		ft_putstr("Total : ");
		ft_putnbr(total_size);
		ft_putstr(" octets\n");
	}
}
