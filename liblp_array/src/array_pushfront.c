/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:00:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/29 22:15:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushfront(t_array	*parray, void	*elem)
{
	size_t	size;
	size_t	elemsize;

	if (array_capacity(*parray) < array_size(*parray) + 1)
		array_grow(*parray, 1);
	if (array_header(*parray)->copy_elem)
		elem = array_header(*parray)->copy_elem(elem);
	size = array_size(*parray);
	elemsize = array_elemsize(*parray);
	if (size)
		lp_memmove((char *)*parray + 1 * elemsize, *parray, size * elemsize);
	lp_memcpy(*parray, elem, elemsize);
	array_set_size(*parray, size + 1);
	return (*parray);
}
