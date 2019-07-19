/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_memory_block.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:40:56 by mdubus            #+#    #+#             */
/*   Updated: 2019/07/19 10:42:07 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*create_new_memory_block(size_t size)
{
	void	*ptr;

	ptr = mmap(0, size, MMAP_PROT, MMAP_FLAGS, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return (ptr);
}
