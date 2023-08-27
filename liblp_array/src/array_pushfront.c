/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:00:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/14 14:02:57 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushfront(t_array	*parray, void	*elem)
{
	size_t	size;
	size_t	elemsize;
	size_t	capacity;

	if (array_capacity(*parray) < array_size(*parray) + 1)
		array_grow(*parray, 1);
	size = array_size(*parray);
	elemsize = array_elemsize(*parray);
	capacity = array_capacity(*parray);
	if (size)
		lp_memmove((char *)*parray + 1 * elemsize, *parray, size * elemsize);
	lp_memcpy(*parray, elem, elemsize);
	array_set_size(*parray, size + 1);
	return (*parray);
}
