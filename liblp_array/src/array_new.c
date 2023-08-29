/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:23 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/29 14:17:07 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_new(size_t capacity, size_t elem_size,
	void (*copy_elem)(void *elem),
	void *(*destroy_elem)(void *elem))
{
	t_array_header	*array_h;

	if (!capacity)
		return (NULL);
	array_h = malloc(capacity * elem_size + sizeof(t_array_header));
	if (!array_h)
		return (NULL);
	array_h->size = 0;
	array_h->capacity = capacity;
	array_h->elem_size = elem_size;
	array_h->copy_elem = copy_elem;
	array_h->destroy_elem = destroy_elem;
	return (array_h->tab);
}
