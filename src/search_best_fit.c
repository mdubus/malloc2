/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_best_fit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:41:14 by mdubus            #+#    #+#             */
/*   Updated: 2019/07/19 12:08:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_header	*search_best_fit(t_header *list, size_t size)
{
	t_header	*best_fit;

	best_fit = NULL;
	while (list != NULL)
	{
		if ((best_fit == NULL || list->size < best_fit->size) &&
				list->size >= size)
			best_fit = list;
		list = list->next;
	}
	return (best_fit);
}
