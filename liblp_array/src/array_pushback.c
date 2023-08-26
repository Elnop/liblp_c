/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:47:57 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/26 03:47:25 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushback(t_array *parray, void *elem)
{
	if (!parray || !*parray)
		return (NULL);
	if (array_capacity(*parray) < array_size(*parray) + 1)
		if (!array_grow(parray, 1))
			return (NULL);
	if (array_header(*parray)->elem_copy)
		elem = array_header(*parray)->elem_copy(elem);
	lp_memcpy((char *)*parray + array_size(*parray), elem,
		array_elemsize(*parray));
	array_set_size(*parray, array_size(*parray) + 1);
	return (*parray);
}
