/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:40:47 by mdubus            #+#    #+#             */
/*   Updated: 2019/07/19 12:15:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*init_large_arena(size_t size)
{
	t_header	*arena;

	arena = NULL;
	if ((arena = init_arena(size)) == NULL)
		return (NULL);
	insert_link_in_list(&l.used, &arena);
	return (arena + sizeof(t_header));
}

t_header	*get_best_fit(int arena_type, size_t padded_size)
{
	t_header	*arena;
	t_header	*best_fit;

	best_fit = search_best_fit(l.free[arena_type], padded_size);
	if (best_fit == NULL)
	{
		if ((arena = init_arena(padded_size)) == NULL)
			return (NULL);
		best_fit = search_best_fit(l.free[arena_type], padded_size);
	}
	return (best_fit);
}

void	*ft_malloc(size_t size)
{
	int			arena_type;
	size_t		padded_size;
	t_header	*best_fit;
	t_header	*arena;

	if (size <= 0)
		return (NULL);
	padded_size = get_padded_size(size);
	arena_type = get_arena_type(padded_size);
	if (arena_type == LARGE)
		return (init_large_arena(padded_size));
	else
	{
		if (l.free[arena_type] == NULL)
		{
			if ((arena = init_arena(padded_size)) == NULL)
				return (NULL);
			insert_link_in_list(&l.free[arena_type], &arena);
		}
		best_fit = get_best_fit(arena_type, padded_size);
		split_block(&best_fit, padded_size);
		detach_link(&l.free[arena_type], &best_fit);
		insert_link_in_list(&l.used, &best_fit);
		return ((void *)best_fit + sizeof(t_header));
	}
	return (0);
}
