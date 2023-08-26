/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushback_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:31:32 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/14 09:47:43 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushback_tab(t_array *parray, void *elems, size_t elems_count)
{
	size_t			i;
	const size_t	elem_size = array_elemsize(*parray);

	if (!parray || !*parray)
		return (NULL);
	if (array_capacity(*parray) < array_size(*parray) + elems_count)
		if (!array_grow(parray,
			elems_count - (array_capacity(*parray) - array_size(*parray))))
			return (NULL);
	i = 0;
	while (i < elems_count)
	{
		if (!array_pushback(parray, (char *)elems + (i * elem_size)))
			return (NULL);
		i++;
	}
	return (*parray);
}
