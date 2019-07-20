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

void	*ft_malloc(size_t size)
{
	int			arena_type;
	t_header	*best_fit;
	size_t		padded_size;

	if (size <= 0)
		return (0);
	arena_type = get_arena_type(size);
	if (arena_type == LARGE)
		printf("LARGE ARENA");
	else
	{
		if (l.free[arena_type] == NULL)
			if (init_arena(arena_type) == 1)
				return (0);
		padded_size = get_padded_size(size);
		best_fit = search_best_fit(l.free[arena_type], padded_size);
		// Si best_fit est null, mmap a nouveau.
		// Si l'arena est null, alors l'arena devient le nouveau block mmap.
		// Si arena est pas null, on place le noveau morceau par adresse.
		split_block(&best_fit, arena_type, padded_size);
		return (best_fit);
	}
	return (0);
}
