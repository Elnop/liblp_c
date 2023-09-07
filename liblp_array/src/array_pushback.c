/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:47:57 by lperroti          #+#    #+#             */
/*   Updated: 2023/09/07 20:50:42 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushback(t_array *parray, void *pelem)
{
	size_t	size;
	size_t	elemsize;

	size = array_size(*parray);
	elemsize = array_elemsize(*parray);
	if (array_capacity(*parray) < size + 1)
		array_grow(parray, 1);
	if (array_header(*parray)->copy_elem)
		(array_header(*parray))
		->copy_elem(pelem, (char *)*parray + size * elemsize);
	else
		lp_memcpy((char *)*parray + size * elemsize, pelem, elemsize);
	array_set_size(*parray, size + 1);
	return (*parray);
}
