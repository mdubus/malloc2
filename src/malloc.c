/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:40:47 by mdubus            #+#    #+#             */
/*   Updated: 2019/07/19 11:37:01 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		get_arena_type(size_t size)
{
	if (size <= MAX_TINY)
		return (TINY);
	if (size <= MAX_SMALL)
		return (SMALL);
	return (LARGE);
}

size_t	get_max_arena_size(int arena_type)
{
	size_t	page_size;

	page_size = getpagesize();
	if (arena_type == TINY)
		return (MAX_TINY * page_size);
	if (arena_type == SMALL)
		return (MAX_SMALL * page_size);
	return (0);
}

int		init_arena(int arena_type)
{
	size_t	max_arena_size;

	max_arena_size = get_max_arena_size(arena_type);
	l.free[arena_type].data = create_new_memory_block(max_arena_size);
	if (l.free[arena_type].data == NULL)
		return (1);
	create_new_link(&l.free[arena_type]);
	l.free[arena_type].size = max_arena_size - sizeof(t_header);
	return (0);
}

void	*ft_malloc(size_t size)
{
	int		arena_type;

	if (size <= 0)
		return (0);
	arena_type = get_arena_type(size);
	if (arena_type == LARGE)
		printf("LARGE ARENA");
	else
	{
		if (l.free[arena_type].data == NULL)
			if (init_arena(arena_type) == 1)
				return (0);
	}
	return (0);
}
