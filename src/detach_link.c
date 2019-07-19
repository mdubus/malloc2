/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:41:09 by mdubus            #+#    #+#             */
/*   Updated: 2019/07/19 10:42:45 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	detach_link(t_header **list, t_header *link)
{
	if (link->prev == NULL)
	{
		*list = link->next;
		(*list)->prev = NULL;
	}
	else if (link->next == NULL)
		link->prev->next = NULL;
	else
	{
		link->prev->next = link->next;
		link->next->prev = link->prev;
	}
	link->prev = NULL;
	link->next = NULL;
}
