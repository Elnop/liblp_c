/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:00:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/10/04 20:17:50 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushfront(t_array	*parray, void	*pelem)
{
	size_t	size;
	size_t	elemsize;

	size = array_size(*parray);
	elemsize = array_elemsize(*parray);
	if (array_capacity(*parray) < size + 1)
		array_grow(parray, 1);
	if (size)
		lp_memmove((char *)*parray + elemsize, *parray, size * elemsize);
	if (array_header(*parray)->copy_elem)
		(array_header(*parray)->copy_elem(pelem, *parray));
	else
		lp_memcpy(*parray, pelem, elemsize);
	array_set_size(*parray, size + 1);
	return (*parray);
}
