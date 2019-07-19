/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padded_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:41:02 by mdubus            #+#    #+#             */
/*   Updated: 2019/07/19 10:41:05 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t	get_padded_size(size_t size)
{
	size_t	padded_size;

	padded_size = size;
	if (padded_size % sizeof(long) != 0)
		padded_size += (sizeof(long) - padded_size % sizeof(long));
	return (padded_size);
}
