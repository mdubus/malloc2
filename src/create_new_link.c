/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:40:52 by mdubus            #+#    #+#             */
/*   Updated: 2019/07/19 10:40:53 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	create_new_link(t_header *link)
{
	link->size = 0;
	link->data = NULL;
	link->prev = NULL;
	link->next = NULL;
}
