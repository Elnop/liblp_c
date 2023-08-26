/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:00:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/25 22:33:33 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushfront(t_array	*parray, void	*elem)
{
	const size_t	size = array_size(*parray);
	const size_t	elemsize = array_elemsize(*parray);
	const size_t	capacity = array_capacity(*parray);

	if (capacity < array_size(*parray) + 1)
		array_grow(*parray, 1);
	if (array_header(*parray)->elem_copy)
		elem = array_header(*parray)->elem_copy(elem);
	if (size)
		lp_memmove((char *)*parray + 1 * elemsize, *parray, size * elemsize);
	lp_memcpy(*parray, elem, elemsize);
	array_set_size(*parray, size + 1);
	return (*parray);
}
